/**
 * Project \
 */


#include "CoBaB.h"
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QTextStream>
#include <algorithm>

/**
 * Dataset implementation
 */

#define PREVIEW_PHOTO {"preview.png","preview.jpg"}
#define VALID_PHOTO_TYPES {"*.jpg", "*.jpeg", "*.bmp", "*.png"}
#define VALID_VIDEO_TYPES {"*.mp4", "*.avi", "*.flv", "*.mkv"}
#define FRAMERATE_FILE "cobab_config.json"
#define ANNOTATION_FILE "annotations"
#define ANNOTATION_EXTENSION ".ann"


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


bool isLess(QPair<QString,Annotation> firstPair, QPair<QString,Annotation> secondPair) {
    return firstPair.first < secondPair.first;
}

QList<QPair<int, Annotation>> Dataset::createVideoAnnotations(QString path) {
    QList<QPair<QString, Annotation>> annotationsWithName = parseAnnotations(path);
    QList<QPair<int, Annotation>> *annotations = new QList<QPair<int, Annotation>>;
    std::sort(annotationsWithName.begin(), annotationsWithName.end(), isLess);
    for(int i = 0; i < annotationsWithName.size(); i++) {
        QPair<int,Annotation> pair(i, annotationsWithName.at(i).second);
        annotations->append(pair);
    }
    return *annotations;
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
            QList<QPair<int, Annotation>> annotations = createVideoAnnotations(file.dir().path()+ANNOTATION_FILE+ANNOTATION_EXTENSION);
            SingleFrameVideo sfvideo(file.dir().path(), annotations);
            mMediaList.append(sfvideo);
        }
    }
    return successful;
}

// creates a list of videos, if possible
bool Dataset::createVideoDataset() {
    QStringList videoFilter(VALID_VIDEO_TYPES);
    QDirIterator videoIter(mPath, videoFilter, QDir::Filter::Files, QDirIterator::Subdirectories);
    if(videoIter.hasNext()) {
        mDatasetType = DatasetType::VIDEO;
        while(videoIter.hasNext()) {
            QString filepath = videoIter.next();
            QFileInfo file(filepath);
            QList<QPair<int, Annotation>> annotations = createVideoAnnotations(file.baseName()+ANNOTATION_EXTENSION);
            Video video(filepath, annotations);
            mMediaList.append(video);
        }
        return true;
    }
    return false;
}

// creates a list of photos, if possible
bool Dataset::createPhotoDataset() {
    QList<QPair<QString, Annotation>> annotationsWithName = parseAnnotations(mPath+ANNOTATION_FILE+ANNOTATION_EXTENSION);
    QList<QPair<int, Annotation>> *annotations = new QList<QPair<int, Annotation>>;

    QStringList photoFilter(VALID_PHOTO_TYPES);
    QDirIterator photoIter(mPath, photoFilter, QDir::Filter::Files, QDirIterator::Subdirectories);
    bool isPhotoDir = false;
    QString photoPath;
    QStringList preview(PREVIEW_PHOTO);
    while(photoIter.hasNext()) {
        photoPath = photoIter.next();
        if(!preview.contains(photoPath)){
            // the dataset doesn't just contain preview photos, so it's a real photo dataset
            if(!isPhotoDir) {
                mDatasetType = DatasetType::PHOTO;
                isPhotoDir = true;
            }
            annotations->clear();
            for(int i = 0; i < annotationsWithName.size(); i++) {
                if(annotationsWithName.at(i).first == photoPath){
                    QPair<int, Annotation> pair(0, annotationsWithName.at(i).second);
                    annotations->append(pair);
                }
            }
            Photo photo(photoPath, *annotations);
            mMediaList.append(photo);
        }
    }
    return isPhotoDir;
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


QList<QPair<QString, Annotation>> Dataset::parseAnnotations(QString filepath) {
    QList<QPair<QString, Annotation>> *annotations = new QList<QPair<QString, Annotation>>;
    QFile file(filepath);
    if(file.exists() && file.open(QFile::ReadOnly)) {
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

            QString imagePath = list.at(0);
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
                QPair<QString, Annotation> pair(imagePath, annotation);
                annotations->append(pair);
            }
        }
    }
    return *annotations;
}
