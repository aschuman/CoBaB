#include "Dataset.h"
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QTextStream>
#include <algorithm>

/**
 * @brief Dataset::Dataset Creates a new Dataset with the given path.
 * @param path The path of the Dataset.
 */
Dataset::Dataset(const QString path) {
    QDir dir(path);
    if(!dir.exists()) {
        return;
    }
    mPath = dir.absolutePath();
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

/**
 * @brief isLess Compares two annotations.
 * @param firstPair The first Annotation with its path.
 * @param secondPair The second Annotation with its path.
 * @return True if the path of the first Annotation is less than the path of the second Annotation.
 */
bool isLess(QPair<QString,Annotation*> firstPair, QPair<QString,Annotation*> secondPair) {
    return firstPair.first < secondPair.first;
}

/**
 * @brief Dataset::createVideoAnnotations Creates an Annotation list for videos.
 * @param path The path to the Annotation file.
 * @return The list of Annotations.
 */
QList<QPair<int, Annotation*>> Dataset::createVideoAnnotations(QString path) {
    QList<QPair<QString, Annotation*>> annotationsWithName = parseAnnotations(path);
    QList<QPair<int, Annotation*>> *annotations = new QList<QPair<int, Annotation*>>;
    if(annotationsWithName.isEmpty()) {
        return *annotations;
    }
    std::sort(annotationsWithName.begin(), annotationsWithName.end(), isLess);

    int j = 0;
    QString frame = annotationsWithName.at(0).first;
    for(int i = 0; i < annotationsWithName.size(); i++) {
        if (annotationsWithName.at(i).first != frame) {
            frame = annotationsWithName.at(i).first;
            j++;
        }
        QPair<int,Annotation*> pair(j, annotationsWithName.at(i).second);
        if(pair.second != nullptr) {
            annotations->append(pair);
        }
    }
    return *annotations;
}

/**
 * @brief Dataset::createSingleFrameVideoDataset Creates a SingleFrameVideo Dataset.
 * @return True if the creation was successful.
 */
bool Dataset::createSingleFrameVideoDataset() {
    bool successful = false;
    QStringList filters(FRAMERATE_FILE);
    QTextStream s(stdout);
    QDirIterator iter(mPath, filters, QDir::Filter::Files, QDirIterator::Subdirectories);
    while(iter.hasNext()) {
        QString filepath = iter.next();
        if(containsFps(filepath)) {
            if(!successful) {
                mType = Type::SINGLE_FRAME_VIDEO;
                successful = true;
            }
            QFileInfo file(filepath);
            QList<QPair<int, Annotation*>> annotations = createVideoAnnotations(file.dir().path()+"/"+ANNOTATION_FILE+ANNOTATION_EXTENSION);
            SingleFrameVideo* sfvideo = new SingleFrameVideo(file.dir().path(), annotations);
            mMediaList.append(sfvideo);
        }
    }
    return successful;
}

/**
 * @brief Dataset::createVideoDataset Creates a video Dataset.
 * @return True if the creation was successful.
 */
bool Dataset::createVideoDataset() {
    QStringList videoFilter(VALID_VIDEO_TYPES);
    QDirIterator videoIter(mPath, videoFilter, QDir::Filter::Files, QDirIterator::Subdirectories);
    if(videoIter.hasNext()) {
        mType = Type::VIDEO;
        while(videoIter.hasNext()) {
            QString filepath = videoIter.next();
            QFileInfo file(filepath);
            QList<QPair<int, Annotation*>> annotations = createVideoAnnotations(file.baseName()+ANNOTATION_EXTENSION);
            Video* video = new Video(filepath, annotations);
            mMediaList.append(video);
        }
        return true;
    }
    return false;
}

/**
 * @brief Dataset::createPhotoDataset Creates a Photo Dataset.
 * @return True if the creation was successful.
 */
bool Dataset::createPhotoDataset() {
    QList<QPair<QString, Annotation*>> annotationsWithName = parseAnnotations(mPath+"/"+ANNOTATION_FILE+ANNOTATION_EXTENSION);
    QList<QPair<int, Annotation*>> *annotations = new QList<QPair<int, Annotation*>>;

    QStringList photoFilter(VALID_PHOTO_TYPES);
    QDirIterator photoIter(mPath, photoFilter, QDir::Filter::Files, QDirIterator::Subdirectories);
    bool isPhotoDir = false;
    QString photoPath;
    QStringList preview(PREVIEW_PHOTO);
    while(photoIter.hasNext()) {
        photoPath = photoIter.next();
        QFileInfo file(photoPath);
        QString fileName = file.fileName();
        if(!preview.contains(fileName)){
            // the dataset doesn't just contain preview photos, so it's a real photo dataset
            if(!isPhotoDir) {
                mType = Type::PHOTO;
                isPhotoDir = true;
            }
            annotations->clear();
            for(int i = 0; i < annotationsWithName.size(); i++) {
                if(annotationsWithName.at(i).first == fileName){
                    QPair<int, Annotation*> pair(0, annotationsWithName.at(i).second);
                    annotations->append(pair);
                }
            }
            Photo* photo = new Photo(photoPath, *annotations);
            mMediaList.append(photo);
        }
    }
    return isPhotoDir;
}

/**
 * @brief Dataset::containsFps Checks if the configuration file contains an entry for frames per second.
 * @param filepath The path of the configuration file.
 * @return True if the configuration file contains an entry for frames per second.
 */
bool Dataset::containsFps(QString filepath) {
    QFile loadFile(filepath);
    if (loadFile.open(QIODevice::ReadOnly)) {
        QByteArray saveData = loadFile.readAll();
        QJsonParseError *error = new QJsonParseError();
        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData, error));
        if(error->error == QJsonParseError::NoError) {
            if(loadDoc.object()["fps"].isDouble()) {
                loadFile.close();
                return true;
            }
        }
    }
    loadFile.close();
    return false;
}

/**
 * @brief Dataset::getName Returns the name of the Dataset.
 * @return The name of the Dataset.
 */
QString Dataset::getName() const {
    return mName;
}

/**
 * @brief Dataset::getNumberOfMedia Returns the number of Medium in this Dataset.
 * @return The number of Medium in this Dataset.
 */
int Dataset::getNumberOfMedia() const {
    return mMediaList.size();
}

/**
 * @brief Dataset::getPreviewPhoto Returns the preview photo of this Dataset.
 * @return The preview photo of this Dataset.
 */
QImage Dataset::getPreviewPhoto() const {
    return mPreviewPhoto;
}

/**
 * @brief Dataset::getMediaList Returns the list of Medium in this Dataset.
 * @return The list of Medium in this Dataset.
 */
QList<Medium*> Dataset::getMediaList() const {
    return mMediaList;
}

/**
 * @brief Dataset::getPath Returns the absolute path of the Dataset.
 * @return The path of the Dataset.
 */
QString Dataset::getPath() const {
    return mPath;
}

/**
 * @brief Dataset::getType Returns the Type of the Dataset.
 * @return The Type of the Dataset.
 */
Dataset::Type Dataset::getType() const {
    return mType;
}

/**
 * @brief Dataset::createPreviewPhoto Creates a preview photo for the Dataset.
 */
void Dataset::createPreviewPhoto() {
    QStringList filters(PREVIEW_PHOTO);
    QDirIterator iter(mPath, filters, QDir::Filter::Files, QDirIterator::Subdirectories);
    if(iter.hasNext()) {
       mPreviewPhoto = QImage(iter.next());
    } else {
        if(mType == Type::PHOTO) {
            //first photo in the list
            QImage preview(mMediaList.first()->getPath());
            mPreviewPhoto = preview;
        } else if(mType == Type::SINGLE_FRAME_VIDEO) {
            //first frame in the first single frame video
            SingleFrameVideo *sfvideo = (SingleFrameVideo*)mMediaList.first();
            if(sfvideo->getFrameList().isEmpty()) {
                return;
            }
            QImage preview(sfvideo->getPath() + "/" + sfvideo->getFrameList().first());
            mPreviewPhoto = preview;
        } else if(mType == Type::VIDEO) {
            QImage preview(VIDEO_ICON);
            mPreviewPhoto = preview;
        }
    }
}

/**
 * @brief Dataset::parseAnnotations Parses the Annotations from the Annotation file.
 * @param filepath The path to the Annotation file.
 * @return The list of Annotation for this Dataset.
 */
QList<QPair<QString, Annotation*>> Dataset::parseAnnotations(QString filepath) {
    QList<QPair<QString, Annotation*>> *annotations = new QList<QPair<QString, Annotation*>>;
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
            if(2+quantity*count > list.size()) {
                continue;
            }
            for(int i = 0; i < quantity; i++) {
                QString id = list.at(idPos+i*count);
                int x = list.at(xPos+i*count).toDouble();
                int y = list.at(yPos+i*count).toDouble();
                int width = list.at(widthPos+i*count).toDouble();
                int height = list.at(heightPos+i*count).toDouble();
                QString type = list.at(typePos+i*count);

                RectangleAnnotation* annotation = new RectangleAnnotation(id, type);
                annotation->setRect(x, y, width, height);
                QPair<QString, Annotation*> pair(imagePath, annotation);
                annotations->append(pair);
            }
            if(quantity == 0) {
                QPair<QString, Annotation*> pair(imagePath, nullptr);
                annotations->append(pair);
            }
        }
        file.close();
    }
    return *annotations;
}
