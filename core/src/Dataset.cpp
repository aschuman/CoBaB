/**
 * Project \
 */


#include "CoBaB.h"
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QTextStream>

/**
 * Dataset implementation
 */

#define PREVIEW_PHOTO {"preview.png","preview.jpg"}
#define VALID_PHOTO_TYPES {"*.jpg", "*.jpeg", "*.bmp", "*.png"}
#define VALID_VIDEO_TYPES {"*.mp4", "*.avi", "*.flv", "*.mkv"}
#define FRAMERATE_FILE "cobab_config.json"
#define ANNOTATION_FILE "annotations.persontracks"


/**
 * @param path
 */
Dataset::Dataset(QString path) {
    mPath = path;
    QDir dir(path);
    if(!dir.exists()) {
        return;
    }
    mName = dir.dirName();

    if(!createSingleFrameVideoDataset()) {
        if(!createPhotoDataset()) {
            if(!createVideoDataset()) {
                return;
            }
        }
    }

    createPreviewPhoto();
}


// creates a list of single frame videos, if possible
bool Dataset::createSingleFrameVideoDataset() {   
    bool successful = false;
    QStringList filters(FRAMERATE_FILE);
    QDirIterator iter(mPath, filters, QDir::Filter::Files, QDirIterator::Subdirectories);
    while(iter.hasNext()) {
        QString filepath = iter.next();
        if(containsFps(filepath)) {
            if(!successful) {
                mDatasetType = DatasetType::SINGLE_FRAME_VIDEO;
                successful = true;
            }
            QFileInfo file(filepath);
            QList<QPair<int, Annotation>> annotations = parse(file.dir().path()+ANNOTATION_FILE);
            SingleFrameVideo sfvideo(file.dir().path(), annotations);
            mMediaList.append(sfvideo);
        }
    }
    return successful;
}

// creates a list of videos, if possible
bool Dataset::createVideoDataset() {
    QList<QPair<int, Annotation>> *annotations = new QList<QPair<int, Annotation>>;
    QStringList videoFilter(VALID_VIDEO_TYPES);
    QDirIterator videoIter(mPath, videoFilter, QDir::Filter::Files, QDirIterator::Subdirectories);
    if(videoIter.hasNext()) {
        mDatasetType = DatasetType::VIDEO;
        while(videoIter.hasNext()) {
            Video video(videoIter.next(), *annotations);
            mMediaList.append(video);
        }
        return true;
    }
    return false;
}

// creates a list of photos, if possible
bool Dataset::createPhotoDataset() {
    QList<QPair<int, Annotation>> *annotations = new QList<QPair<int, Annotation>>;
    QStringList photoFilter(VALID_PHOTO_TYPES);
    QDirIterator photoIter(mPath, photoFilter, QDir::Filter::Files, QDirIterator::Subdirectories);
    if(photoIter.hasNext()) {
        QString photoPath = photoIter.next();
        while(photoIter.hasNext()) {
            QStringList preview(PREVIEW_PHOTO);
            if(!preview.contains(photoPath)){
                // the dataset doesn't just contain preview photos, so it's a real photo dataset
                mDatasetType = DatasetType::PHOTO;
                while(photoIter.hasNext()) {
                    photoPath = photoIter.next();
                    if(!preview.contains(photoPath)) {
                        Photo photo(photoPath, *annotations);
                        mMediaList.append(photo);
                    }
                }
                return true;
            }
            photoPath = photoIter.next();
        }
    }
    return false;
}

bool Dataset::containsFps(QString filepath) {
    QFile loadFile(filepath);
    if (loadFile.open(QIODevice::ReadOnly)) {
        QByteArray saveData = loadFile.readAll();
        QJsonParseError *error = new QJsonParseError();
        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData, error));
        if(error->error == QJsonParseError::NoError) {
            if(!(loadDoc.object()["fps"].isUndefined())) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @return QString
 */
QString Dataset::getName() {
    return mName;
}

/**
 * @return int
 */
int Dataset::getNumberOfMedia() {
    return mMediaList.size();
}

/**
 * @return QImage
 */
QImage Dataset::getPreviewPhoto() {
    return mPreviewPhoto;
}

/**
 * @return QList<Medium>
 */
QList<Medium> Dataset::getMediaList() {
    return mMediaList;
}

/**
 * @return QString
 */
QString Dataset::getPath() {
    return mPath;
}

/**
 * @return DatasetType
 */
DatasetType Dataset::getType() {
    return mDatasetType;
}

void Dataset::createPreviewPhoto() {
    QStringList filters(PREVIEW_PHOTO);
    QDirIterator iter(mPath, filters, QDir::Filter::Files, QDirIterator::Subdirectories);
    if(iter.hasNext()) {
       mPreviewPhoto = QImage(iter.next());
    } else {
        if(mDatasetType == DatasetType::PHOTO) {
            //first photo in the list
            QImage preview(mMediaList.first().getPath());
            mPreviewPhoto = preview;
        } else if(mDatasetType == DatasetType::SINGLE_FRAME_VIDEO) {
            //first frame in the first single frame video
            /*SingleFrameVideo sfvideo = (SingleFrameVideo)(mMediaList.first());
            QImage preview(sfvideo.getFrameList().first());
            mPreviewPhoto = preview;*/
        } else if(mDatasetType == DatasetType::VIDEO) {

        }
    }
}


QList<QPair<int, Annotation>> Dataset::parse(QString filepath) {
    QList<QPair<int, Annotation>> *annotations = new QList<QPair<int, Annotation>>;
    QFile file(filepath);
    if(file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString line;
        stream.readLine(); // first line

        stream.readLineInto(&line); //header line
        QStringList list = line.split(" ", QString::SkipEmptyParts);
        //the positions in the line (so it's no problem, if the positions change)
        int count = list.first().toInt(); // number of arguments
        int idPos = list.indexOf("id")+1;
        int xPos = list.indexOf("x")+1;
        int yPos = list.indexOf("y")+1;
        int widthPos = list.indexOf("width")+1;
        int heightPos = list.indexOf("height")+1;
        int typePos = list.indexOf("class")+1;

        // read in the annotations
        while (stream.readLineInto(&line)) {
            QStringList list = line.split(" ", QString::SkipEmptyParts);

            QString imagePath = list.at(0); // *framenumber.VALID_PHOTO_TYPE
            QStringList imagePathSplitted = imagePath.split(".");
            imagePathSplitted.removeLast();
            imagePath = imagePathSplitted.join("."); // *framenumber (same string without the extension)
            QRegExp rx("(\\d+)");
            QStringList numberList; // list of all numbers in imagePath
            int pos = 0;
            while ((pos = rx.indexIn(imagePath, pos)) != -1) {
                numberList << rx.cap(1);
                pos += rx.matchedLength();
            }
            int framenumber = numberList.last().toInt();

            int quantity = list.at(1).toInt(); // number of annotations
            for(int i = 0; i < quantity; i++) {
                QString id = list.at(idPos+i*count);
                int x = list.at(xPos+i*count).toInt();
                int y = list.at(yPos+i*count).toInt();
                int width = list.at(widthPos+i*count).toInt();
                int height = list.at(heightPos+i*count).toInt();
                QString type = list.at(typePos+i*count);

                RectangleAnnotation annotation(id, type);
                annotation.setRect(x, y, width, height);
                QPair<int, Annotation> pair(framenumber, annotation);
                annotations->append(pair);
            }
        }
    }
    return *annotations;
}
