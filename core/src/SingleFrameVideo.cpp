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

#define FRAMERATE_FILE "cobab_config.json"
#define DEFAULT_FRAMERATE 24
#define VALID_FILE_TYPES {"*.jpg","*.jpeg","*.bmp","*.png"}

/**
 * @param path
 */
SingleFrameVideo::SingleFrameVideo(QString path, QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mMediumType = MediumType::SINGLE_FRAME_VIDEO;

    QDir dir(mRelativePath);

    QStringList filters (VALID_FILE_TYPES);
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Filter::Files);
    dir.setSorting(QDir::SortFlag::Name);

    mFrameList = dir.entryList();

    if(dir.exists(FRAMERATE_FILE)) {
        readFramerateFromJson(FRAMERATE_FILE);
    }

    std::sort(mFrameList.begin(), mFrameList.end());
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
