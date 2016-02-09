/**
 * Project \
 */


#include "SingleFrameVideo.h"
#include <QDir>
#include <QTextStream>
#include <algorithm>
#include <QJsonObject>
#include <QJsonDocument>

/**
 * SingleFrameVideo implementation
 */


/**
 * @param path
 */
SingleFrameVideo::SingleFrameVideo(const QString path, const QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mType = Type::SINGLE_FRAME_VIDEO;

    QDir dir(mRelativePath);

    QStringList filters (VALID_PHOTO_TYPES);
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Filter::Files);
    dir.setSorting(QDir::SortFlag::Name);

    mFrameList = dir.entryList();

    if(dir.exists(FRAMERATE_FILE)) {
        mFramerate = readFramerateFromJson(mRelativePath+"/"+FRAMERATE_FILE);
    }

    std::sort(mFrameList.begin(), mFrameList.end());
}

/**
 * @return int
 */
double SingleFrameVideo::getFramerate() const {
    return mFramerate;
}

/**
 * @return QList<QString>
 */
QList<QString> SingleFrameVideo::getFrameList() const {
    return mFrameList;
}

double SingleFrameVideo::readFramerateFromJson(const QString path) {
    QFile loadFile(path);
    if (!loadFile.open(QIODevice::ReadOnly)) {
            return DEFAULT_FRAMERATE;
        }

    QByteArray saveData = loadFile.readAll();
    QJsonParseError *error = new QJsonParseError();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData, error));
    if(error->error == QJsonParseError::NoError) {
        QJsonValue fps = loadDoc.object()["fps"];
        if(fps.isDouble()) {
            return fps.toDouble();
        }
    }
    return DEFAULT_FRAMERATE;
}
