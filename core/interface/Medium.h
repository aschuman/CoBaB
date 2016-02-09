/**
 * Project \
 */


#ifndef _MEDIUM_H
#define _MEDIUM_H

#include "Annotation.h"

class Medium {

public: 
    enum Type { PHOTO, VIDEO, SINGLE_FRAME_VIDEO };
    Medium(const QString path, const QList<QPair<int, Annotation>> annotations);
    Type getType() const;
    QList<QPair<int, Annotation>> getAnnotationList() const;
    QString getPath() const;

protected: 
    QString mRelativePath;
    Type mType;
    QList<QPair<int, Annotation>> mAnnotationList;
};

#endif //_MEDIUM_H
