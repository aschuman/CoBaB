#include "image.h"

Image::Image(const QString& file) : Medium(file)
{

}

QImage Image::get() const
{
    return QImage(file);
}

