/**
 * Project \
 */


#include "CoBaB.h"
#include <QDir>
#include <QTextStream>
#include <algorithm>
#include <QJsonObject>
#include <QJsonDocument>

/**
 * SingleFrameVideo implementation
 */

#define FRAMERATE_FILE "framerate.txt"
#define DEFAULT_FRAMERATE 24
#define VALID_FILE_TYPES "*.jpg|*.jpeg|*.bmp|*.png"

/**
 * @param path
 */
SingleFrameVideo::SingleFrameVideo(QString path, QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mMediumType = MediumType::SINGLE_FRAME_VIDEO;

    QDir dir(mRelativePath);
    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Type);
    mFrameList = dir.entryList();
    QListIterator<QString> iterator(mFrameList);
    while (iterator.hasNext()) {
        QString fileName = iterator.next();
        if(fileName == FRAMERATE_FILE) {
            mFrameList.removeOne(fileName);
            mFramerate = readFramerateFromJson(fileName);
            break;
        }
    }
    iterator.toFront();
    while(iterator.hasNext()) {
        QRegExp rx(VALID_FILE_TYPES);
        QString file = iterator.next();
        if(!rx.exactMatch(file)) {
            mFrameList.removeOne(file);
        }
    }

    struct {
        bool operator()(QPair<int, Annotation> a, QPair<int, Annotation> b) {
            return a.first < b.first;
        }
    } customLess;
    std::sort(mAnnotationList.begin(), mAnnotationList.end(), customLess);

}

/**
 * @return int
 */
double SingleFrameVideo::getFramerate() {
    return mFramerate;
}

/**
 * @return QList<QString>
 */
QList<QString> SingleFrameVideo::getFrameList() {
    return mFrameList;
}

double readFramerateFromJson(QString path) {
    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadOnly)) {
            return DEFAULT_FRAMERATE;
        }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    return loadDoc.object()["fps"].toDouble();
}
