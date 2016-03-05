#ifndef _MEDIUM_H
#define _MEDIUM_H

#include "RectangleAnnotation.h"

/**
 * @brief A Medium is an element of a Dataset.
 * @author Marie
 *
 * It is characterized by its path. The Medium contains a list of Annotation and the corresponding index.
 * The index is 0 if it is a Photo. Otherwise the index specifies the frame in which the Annotation is.
 */
class Medium {

public:
    /**
     * @brief The Medium Type can be PHOTO, VIDEO or SINGLE_FRAME_VIDEO.
     */
    enum Type { PHOTO, VIDEO, SINGLE_FRAME_VIDEO };
    Medium(const QString path, const QList<QPair<int, Annotation*>> annotations);
    Medium(const Medium& other);
    virtual Medium* copy();
    ~Medium();
    Type getType() const;
    QList<QPair<int, Annotation *>> getAnnotationList() const;
    QString getPath() const;

protected: 
    QString mPath;                                      ///< The absolute path to the Medium.
    Type mType;                                         ///< The type of the Medium.
    QList<QPair<int, Annotation*>> mAnnotationList;     ///< The list of Annotation which belong to the Medium.
};

#endif //_MEDIUM_H
