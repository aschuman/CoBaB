#ifndef IMAGE_H
#define IMAGE_H
#include <qimage.h>
#include "medium.h"

class Image : public Medium {
public:
    explicit Image(const QString& file);

    QImage get() const;
};

#endif // IMAGE_H
