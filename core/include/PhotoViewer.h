#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QWidget>
#include "ViewerPageWidget.h"

/**
 * @brief The PhotoViewer class
 * @author Anja
 */
class PhotoViewer : public ViewerPageWidget
{
    Q_OBJECT

public:
    explicit PhotoViewer();
    ~PhotoViewer();
    void display() override;
};

#endif // PHOTOVIEWER_H
