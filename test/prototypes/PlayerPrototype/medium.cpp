#include "medium.h"

Medium::Medium(QString file, QList<Annotation> annotations)
    : file(file),
      annotations(annotations)
{

}

QString Medium::getFile() const
{
    return file;
}

QList<Medium::Annotation>::const_iterator Medium::beginAnnotations() const
{
    return annotations.begin();
}

QList<Medium::Annotation>::const_iterator Medium::endAnnotatoins() const
{
    return annotations.end();
}


Medium::Annotation::Annotation(int frame, QRect rect) : frame(frame), rect(rect)
{
}

int Medium::Annotation::getFrame() const
{
    return frame;
}

QRect Medium::Annotation::getRect() const
{
    return rect;
}
