#include "SearchResultModel.h"

#include <QPair>
#include <QBrush>
#include "SearchResultElementFeedback.h"

SearchResultModel::SearchResultModel() {
    mSearchResult = nullptr;
}

/**
 * @brief Sets the SearchResult to be prepared by this model for a view.
 *
 * Does not take ownership of searchResult.
 * A nullptr for searchResult indicates the absence of any result.
 *
 * @param searchResult The SearchResult.
 */
void SearchResultModel::setSearchResult(const SearchResult* searchResult)
{
    mSearchResult = searchResult;
    mFeedbacks.clear();
    emit layoutChanged();
}

/**
 * @brief Returns the Feedback as set in the respective view.
 * @return The feedback.
 */
SearchFeedback SearchResultModel::getFeedback() const
{
    QList<QPair<SearchObject, int>> feedbackList;
    if(mSearchResult){
        auto searchResultList = mSearchResult->getSearchResultList();
        for(size_t i = 0; i < searchResultList.size(); ++i){
            auto it = mFeedbacks.find(i);
            QPair<SearchObject, int> feedback;
            feedback.first = searchResultList.at(i).getSearchObject();
            if(it != mFeedbacks.end()){
                feedback.second = *it;
            }
            feedbackList.push_back(feedback);
        }
    }
    SearchFeedback searchFeedback("Dual"); // todo
    searchFeedback.setFeedbackList(feedbackList);
    return searchFeedback;
}

/**
 * @brief Implementation of QAbstractListModel::rowCount.
 * @param parent
 * @return
 */
int SearchResultModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mSearchResult ? mSearchResult->getSearchResultList().size() : 0;
}

/**
 * @brief Implementation of QAbstractListModel::data
 * @param index
 * @param role
 * @return
 */
QVariant SearchResultModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    switch (role) {
    case Qt::DisplayRole:
        if(mSearchResult && index.row() < mSearchResult->getSearchResultList().size()){
            SearchObject searchObject = mSearchResult->getSearchResultList().at(index.row()).getSearchObject();
            SearchResultElementFeedback element;
            if(searchObject.getMediumIndex() == 0) { // photo dataset
                element.img = QImage(searchObject.getMedium()).scaledToHeight(100);
            } else if(searchObject.getMediumIndex() == 1) { // single frame video dataset
                Dataset dataset(searchObject.getMedium());
                element.img = dataset.getPreviewPhoto();
            }
            auto it = mFeedbacks.find(index.row());
            if(it != mFeedbacks.end())
                element.rating = *it;
            else
                element.rating = 0;
            result.setValue(element);
        }
        break;

    default:
        break;

    case Qt::BackgroundRole:
        QBrush brush;
        brush.setColor(Qt::GlobalColor::red);
        result = brush;
        break;
    }
    return result;
}

/**
 * @brief Implementation of QAbstractListModel::setData
 * @param index
 * @param value
 * @param role
 * @return
 */
bool SearchResultModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    bool result = false;
    if(value.canConvert<int>()){
        mFeedbacks.insert(index.row(), value.toInt());
    }
    return result;
}

/**
 * @brief Implementation of QAbstractListModel::flags
 * @param index
 * @return
 */
Qt::ItemFlags SearchResultModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
