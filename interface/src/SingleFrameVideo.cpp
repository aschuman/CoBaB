#include "SingleFrameVideo.h"
#include <QDir>
#include <QTextStream>
#include <algorithm>
#include <QJsonObject>
#include <QJsonDocument>
#include "log.h"

/**
 * @brief SingleFrameVideo::SingleFrameVideo Constructs a SingleFrameVideo.
 * @param path The path to the SingleFrameVideo.
 * @param annotations The Annotations which belong to the SingleFrameVideo.
 */
SingleFrameVideo::SingleFrameVideo(const QString path, const QList<QPair<int, Annotation*>> annotations)
    : Medium(path, annotations) {
    mType = Type::SINGLE_FRAME_VIDEO;

    QDir dir(mPath);

    QStringList filters (VALID_PHOTO_TYPES);
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Filter::Files);
    dir.setSorting(QDir::SortFlag::Name);

    mFrameList = dir.entryList();

    if(!dir.exists(FRAMERATE_FILE)) {
        mFramerate = -1;
        LOG_ERR("The framerate file does not exists.");
    }
    mFramerate = readFramerateFromJson(mPath+"/"+FRAMERATE_FILE);
}

/**
 * @brief SingleFrameVideo::SingleFrameVideo Constructs a SingleFrameVideo as a copy of other.
 * @param other Another SingleFrameVideo that is copied.
 */
SingleFrameVideo::SingleFrameVideo(const SingleFrameVideo& other)
    : Medium(other) {
    mFramerate = other.getFramerate();
    mFrameList = other.getFrameList();
}

/**
 * @brief SingleFrameVideo::operator = Sets this SingleFrameVideo to other.
 * @param other The other SingleFrameVideo.
 * @return This SingleFrameVideo.
 */
SingleFrameVideo& SingleFrameVideo::operator=(const SingleFrameVideo& other) {
    mPath = other.mPath;
    mType = other.mType;
    mAnnotationList = other.mAnnotationList;
    mFramerate = other.mFramerate;
    mFrameList = other.mFrameList;
    return *this;
}

/**
 * @brief SingleFrameVideo::copy Copies this SingleFrameVideo.
 * @return A copy of this SingleFrameVideo.
 */
Medium* SingleFrameVideo::copy() {
    return new SingleFrameVideo(*this);
}

/**
 * @brief SingleFrameVideo::getFramerate Returns the framerate of the SingleFrameVideo.
 * @return The framerate of the SingleFrameVideo.
 */
double SingleFrameVideo::getFramerate() const {
    return mFramerate;
}

/**
 * @brief SingleFrameVideo::getFrameList Returns the list of frames.
 * @return The list of frames.
 */
QList<QString> SingleFrameVideo::getFrameList() const {
    return mFrameList;
}

/**
 * @brief SingleFrameVideo::readFramerateFromJson Reads the framerate from the configuration file.
 * @param path The path to the configuration file.
 * @return The framerate which was specified in the configuration file. Returns the default framerate if the configuration file does not contain the framerate.
 */
double SingleFrameVideo::readFramerateFromJson(const QString path) {
    QFile loadFile(path);
    if (!loadFile.open(QIODevice::ReadOnly)) {
            LOG_ERR("The framerate file couldn't be opened.");
            return DEFAULT_FRAMERATE;
        }

    QByteArray saveData = loadFile.readAll();
    QJsonParseError *error = new QJsonParseError();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData, error));
    if(error->error == QJsonParseError::NoError) {
        QJsonValue fps = loadDoc.object()["fps"];
        if(fps.isDouble()) {
            if(fps.toDouble() >= 0.0) {
                return fps.toDouble();
            }
        }
        LOG_ERR("The framerate is no positive number.");
    } else {
        LOG_ERR(error->errorString());
    }
    return -1;
}
