#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QWidget>
#include "ViewerPageWidget.h"

/**
 * @brief The PhotoViewer class is a ViewerPageWidget which can only show Photos.
 * @author Anja
 */
class PhotoViewer : public ViewerPageWidget
{
    Q_OBJECT

public:
    explicit PhotoViewer();
    void display() override;
    QString getSearchMedium() override;
};

#endif // PHOTOVIEWER_H
