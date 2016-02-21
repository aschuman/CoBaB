#ifndef ANNOTATIONGRAPHICSITEMFACTORY_H
#define ANNOTATIONGRAPHICSITEMFACTORY_H

#include "ClickableGraphicsRectItem.h"
#include "Annotation.h"

/**
 * @brief The AnnotationGraphicsItemFactory class
 * @author Anja
 */
class AnnotationGraphicsItemFactory
{
public:
    AnnotationGraphicsItemFactory();
    QGraphicsItem* getAnnotationVisualizer(Annotation* annotation);
};

#endif // ANNOTATIONGRAPHICSITEMFACTORY_H
