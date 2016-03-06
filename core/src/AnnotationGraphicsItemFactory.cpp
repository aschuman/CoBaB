#include "AnnotationGraphicsItemFactory.h"

AnnotationGraphicsItemFactory::AnnotationGraphicsItemFactory()
{

}

QGraphicsItem* AnnotationGraphicsItemFactory::getAnnotationVisualizer(Annotation* annotation) {
    if(annotation != nullptr) {
        if(annotation->getForm() == Annotation::Form::RECTANGLE) {
            return new ClickableGraphicsRectItem((RectangleAnnotation*)annotation);
        }
    }
    return nullptr;
}
