#ifndef VIEWERPAGEWIDGET_H
#define VIEWERPAGEWIDGET_H

#include <QWidget>
#include "PageWidget.h"
#include "DatasetList.h"
#include "MediaModel.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


namespace Ui {
class ViewerPageWidget;
}

class ViewerPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit ViewerPageWidget();
    ~ViewerPageWidget();

    void reset() override;

    static const int EXIT_NEXT;

public slots:
    void next();
    void before();
    void clicked(const QModelIndex& index);
    void nextWidget();

private:
    Ui::ViewerPageWidget *ui;
    const Dataset* mDataset;
    MediaModel mModel;
    QGraphicsView mGraphicsView;
    QGraphicsScene mGraphicsScene;
    QGraphicsPixmapItem* mGraphicsItem;
    int mIndex;
    void displayImage();

};

#endif // VIEWERPAGEWIDGET_H
