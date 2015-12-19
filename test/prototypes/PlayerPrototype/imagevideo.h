#ifndef IMAGEVIDEO_H
#define IMAGEVIDEO_H
#include <image.h>
#include "medium.h"

class ImageVideo : public Medium {
public:
    ImageVideo(const QString& file);
};

#endif // IMAGEVIDEO_H
