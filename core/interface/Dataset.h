/**
 * Project \
 */


#ifndef _DATASET_H
#define _DATASET_H

#include "Medium.h"
#include "Configuration.h"
#include <QDir>
#include <QDataStream>
#include <QImage>

class Dataset {

public:
    enum Type { PHOTO, VIDEO, SINGLE_FRAME_VIDEO };
    explicit Dataset(const QString path);
    QString getName() const;
    int getNumberOfMedia() const;
    QImage getPreviewPhoto() const;
    QList<Medium> getMediaList() const;
    QString getPath() const;
    Type getType() const;

protected:
    QString mName;
    QImage mPreviewPhoto;
    QList<Medium> mMediaList;
    QString mPath;
    Type mType;

private: 
    bool createSingleFrameVideoDataset();
    bool createVideoDataset();
    bool createPhotoDataset();
    bool containsFps(const QString filepath);
    void createPreviewPhoto();
    QList<QPair<int, Annotation>> createVideoAnnotations(QString path);
    QList<QPair<QString, Annotation>> parseAnnotations(QString filepath);
};

#endif //_DATASET_H
