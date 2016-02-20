#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QWidget>
#include "ViewerPageWidget.h"

namespace Ui {
class PhotoViewer;
}

class PhotoViewer : public ViewerPageWidget
{
    Q_OBJECT

public:
    explicit PhotoViewer();
    ~PhotoViewer();

private:
    Ui::PhotoViewer *ui;
};

#endif // PHOTOVIEWER_H
