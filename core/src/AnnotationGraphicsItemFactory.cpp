#include "AnnotationGraphicsItemFactory.h"

/**
 * @brief AnnotationGraphicsItemFactory::AnnotationGraphicsItemFactory Constructs an AnnotationGraphicsItemFactory.
 */
AnnotationGraphicsItemFactory::AnnotationGraphicsItemFactory()
{

}

/**
 * @brief AnnotationGraphicsItemFactory::getAnnotationVisualizer Returns a QGraphicsItem dependent on the form of the given Annotation.
 * @param annotation The Annotation for which a QGraphicsItem should be created.
 * @return The QGraphicsItem with the fitting form.
 */
QGraphicsItem* AnnotationGraphicsItemFactory::getAnnotationVisualizer(Annotation* annotation) {
    if(annotation != nullptr) {
        if(annotation->getForm() == Annotation::Form::RECTANGLE) {
            return new ClickableGraphicsRectItem((RectangleAnnotation*)annotation);
        }
    }
    return nullptr;
}
