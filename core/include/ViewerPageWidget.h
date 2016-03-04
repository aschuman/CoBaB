#ifndef VIEWERPAGEWIDGET_H
#define VIEWERPAGEWIDGET_H

#include <QWidget>
#include "PageWidget.h"
#include "DatasetList.h"
#include "MediaModel.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPen>
#include "AnnotationDrawer.h"
#include <ClickableGraphicsPixmapItem.h>


namespace Ui {
class ViewerPageWidget;
}

/**
 * @brief The ViewerPageWidget class
 * @author Anja
 */
class ViewerPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit ViewerPageWidget();
    ~ViewerPageWidget();

    void reset() override;
    void retranslateUi() override;

    static const int EXIT_NEXT;

public slots:
    void next();
    void before();
    void clicked(const QModelIndex& index);
    void nextWidget(QAction* action);
    virtual void contextMenu(const QPointF &pos);
    void on_mGraphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);
    void roiClicked();
    void annotationSelected(Annotation *annotation, const QPointF &pos);

protected:
    Ui::ViewerPageWidget *ui;
    const Dataset* mDataset;
    MediaModel mModel;
    QGraphicsScene mGraphicsScene;
    ClickableGraphicsPixmapItem* mImage;
    int mIndex;

    QPen mSelectionPen;
    QGraphicsRectItem* mCurrentSelection;
    QRect mCurrentRubberBand;

    AnnotationDrawer mAnnotationDrawer;
    Annotation* mSelectedAnnotation;

    QRect mROI;

    virtual void display() = 0;
};

#endif // VIEWERPAGEWIDGET_H
