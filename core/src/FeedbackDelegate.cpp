#include "include/FeedbackDelegate.h"
#include <memory>
#include <QPainter>
#include <QMouseEvent>
#include "SearchObject.h"
#include "SearchResultElementFeedback.h"
#include "DualFeedbackEditor.h"

/**
 * @brief Implementation of QStyledItemDelegate::paint.
 * @param painter
 * @param option
 * @param index
 */
void FeedbackDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //painter->save();
    if(index.data().canConvert<SearchResultElementFeedback>()){
        SearchResultElementFeedback element = index.data().value<SearchResultElementFeedback>();
        QImage scaledImg = element.img.scaled(option.rect.width(), option.rect.height(), Qt::KeepAspectRatio);
        painter->drawImage(option.rect.topLeft(), scaledImg);

        if(element.rating == 0)
            painter->setPen(Qt::black);
        else if(element.rating > 0)
            painter->setPen(Qt::green);
        else
            painter->setPen(Qt::red);

        QRect imageRect(option.rect.x(), option.rect.y(), scaledImg.width(), scaledImg.height());

        painter->drawRect(imageRect);

        painter->setPen(QPen());
        painter->drawText(imageRect, Qt::AlignRight | Qt::AlignTop, QString::number(element.rating));
    }
    //painter->restore();
}

/**
 * @brief Implementation of QStyledItemDelegate::sizeHint.
 * @param option
 * @param index
 * @return
 */
QSize FeedbackDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize hint;
    if(index.data().canConvert<SearchResultElementFeedback>()){
        SearchResultElementFeedback element = index.data().value<SearchResultElementFeedback>();
        hint = element.img.size();
    } else {
        hint = QStyledItemDelegate::sizeHint(option, index);
    }
    return hint;
}

/**
 * @brief Implementation of QStyledItemDelegate::createEditor.
 * @param parent
 * @param option
 * @param index
 * @return
 */
QWidget *FeedbackDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QWidget* editor;
    if(index.data().canConvert<SearchResultElementFeedback>()){
        SearchResultElementFeedback element = index.data().value<SearchResultElementFeedback>();
        DualFeedbackEditor* dfEditor = new DualFeedbackEditor(parent);
        dfEditor->setFeedback(element.rating);
        connect(dfEditor, &DualFeedbackEditor::feedbackChanged, this, &FeedbackDelegate::commit);
        editor = dfEditor;
    } else {
        editor = QStyledItemDelegate::createEditor(parent, option, index);
    }
    return editor;
}

/**
 * @brief Implementation of QStyledItemDelegate::setEditorData.
 * @param editor
 * @param index
 */
void FeedbackDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.data().canConvert<SearchResultElementFeedback>()){
        SearchResultElementFeedback element = index.data().value<SearchResultElementFeedback>();
        FeedbackEditor* e = qobject_cast<FeedbackEditor*>(editor);
        e->setFeedback(element.rating);
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

/**
 * @brief Implementation of QStyledItemDelegate::updateEditorGeometry.
 * @param editor
 * @param option
 * @param index
 */
void FeedbackDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::updateEditorGeometry(editor, option, index);
}

/**
 * @brief Implementation of QStyledItemDelegate::setModelData.
 * @param editor
 * @param model
 * @param index
 */
void FeedbackDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.data().canConvert<SearchResultElementFeedback>()){
        FeedbackEditor* e = qobject_cast<FeedbackEditor*>(editor);
        model->setData(index, e->getFeedback());
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void FeedbackDelegate::commit()
{
    FeedbackEditor* editor = qobject_cast<FeedbackEditor*>(sender());
    emit commitData(editor);
}

