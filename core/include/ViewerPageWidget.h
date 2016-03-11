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
#include "AlgorithmList.h"
#include "SearchQuery.h"
#include <QHash>


namespace Ui {
class ViewerPageWidget;
}

/**
 * @brief The ViewerPageWidget class provides users the possibility to select and view media.
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
    QString getName() override;

    static const int EXIT_NEXT = 0;

public slots:
    void next();
    void before();
    virtual void nextWidget(QAction* action);
    virtual void contextMenu(const QPointF &pos);
    void on_mGraphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);
    void roiClicked();
    void annotationSelected(Annotation *annotation, const QPointF &pos);
    void showToolTip(QAction* action);
    void zoomIn();
    void zoomOut();
    void zoomed(double factor);
    void resize();
    void selectionChanged(const QModelIndex& index, const QModelIndex& previousIndex);

protected:
    Ui::ViewerPageWidget *ui; ///< The ui.
    const Dataset* mDataset; ///< The Datasets whose contents are displayed in this PageWidget.
    MediaModel mModel; ///< The Model for the QListView to show the media.
    QGraphicsScene mGraphicsScene; ///< The GraphicsScene to display the media.
    ClickableGraphicsPixmapItem* mImage; ///< The current selected Medium that is shown in the QGraphicsScene.
    int mIndex; ///< The index of the selected Medium in the media list.

    QPen mSelectionPen; ///< The pen to select a ROI.
    QGraphicsRectItem* mCurrentSelection; ///< The current user defined selection in the QGraphicsScene.
    QRect mCurrentRubberBand; ///< The current user defined selection.
    QRect mROI; ///< The ROI, selected by the user.
    bool mROIIsChosen; ///< Indicates if the ROI button was pressed.

    AnnotationDrawer mAnnotationDrawer; ///< The AnnotationDrawer to draw the annotations on the media.
    Annotation* mSelectedAnnotation; ///< The selected annotation.

    AlgorithmList* mAlgorithmList; ///< A list of available algorithms.
    QHash<QString, Algorithm*> mAlgorithms; ///< Hashes an algorithm name to the algorithm.

    std::shared_ptr<SearchQuery> mSearchQuery; ///< The SearchQuery, filled with the selected Medium and Annotation/ROI.

    double mZoomLevel;

    virtual void display();
    void resizeEvent(QResizeEvent* event) override;
    virtual int getFrameIndex();
};

#endif // VIEWERPAGEWIDGET_H
