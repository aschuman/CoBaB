#include "AnnotationGraphicsItemFactory.h"

AnnotationGraphicsItemFactory::AnnotationGraphicsItemFactory()
{

}

QGraphicsItem* AnnotationGraphicsItemFactory::getAnnotationVisualizer(Annotation* annotation) {
    return new ClickableGraphicsRectItem((RectangleAnnotation*)annotation);
}
