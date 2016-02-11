#ifndef _DATASET_H
#define _DATASET_H

#include "Medium.h"
#include "Video.h"
#include "Photo.h"
#include "SingleFrameVideo.h"
#include "RectangleAnnotation.h"
#include "Configuration.h"
#include <QDir>
#include <QDataStream>
#include <QImage>

/**
 * @brief A Dataset has a Type and contains media of this Type.
 */
class Dataset {

public:
    /**
     * @brief The Dataset Type can be PHOTO, VIDEO or SINGLE_FRAME_VIDEO.
     */
    enum Type { PHOTO, VIDEO, SINGLE_FRAME_VIDEO };
    explicit Dataset(const QString path);
    QString getName() const;
    int getNumberOfMedia() const;
    QImage getPreviewPhoto() const;
    QList<Medium*> getMediaList() const;
    QString getPath() const;
    Type getType() const;

protected:
    QString mName;                  ///< The name of the dataset.
    QImage mPreviewPhoto;           ///< The preview photo of the dataset.
    QList<Medium*> mMediaList;       ///< The list of media contained in the dataset.
    QString mPath;                  ///< The path of the dataset.
    Type mType;                     ///< The type of the dataset.

private: 
    bool createSingleFrameVideoDataset();
    bool createVideoDataset();
    bool createPhotoDataset();
    bool containsFps(const QString filepath);
    void createPreviewPhoto();
    QList<QPair<int, Annotation *> > createVideoAnnotations(QString path);
    QList<QPair<QString, Annotation *> > parseAnnotations(QString filepath);
};

#endif //_DATASET_H
