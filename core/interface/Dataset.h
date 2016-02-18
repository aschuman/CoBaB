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
 * @author Anja
 * @todo The preview image for a video dataset should be the first frame of the first video in the mMediaList.
 */
class Dataset {

public:
    /**
     * @brief The Dataset Type can be PHOTO, VIDEO or SINGLE_FRAME_VIDEO.
     */
    enum Type { PHOTO, VIDEO, SINGLE_FRAME_VIDEO };
    explicit Dataset(const QString& path);
    ~Dataset();
    QString getName() const;
    int getNumberOfMedia() const;
    QImage getPreviewPhoto() const;
    QList<Medium*> getMediaList() const;
    QString getPath() const;
    Type getType() const;
    bool isValid();

private:
    QString mName;                  ///< The name of the dataset.
    QImage mPreviewPhoto;           ///< The preview photo of the dataset.
    QList<Medium*> mMediaList;      ///< The list of media contained in the dataset.
    QString mPath;                  ///< The path of the dataset.
    Type mType;                     ///< The type of the dataset.
    bool mValid;                    ///< The valid flag is true, if the created dataset is valid.

    bool createSingleFrameVideoDataset();
    bool createVideoDataset();
    bool createPhotoDataset();
    bool containsFps(const QString filepath) const;
    bool createPreviewPhoto();
    QList<QPair<int, Annotation*>> createVideoAnnotations(QString path);
    QList<QPair<QString, Annotation*>> parseAnnotations(const QString& filepath);
};

#endif //_DATASET_H
