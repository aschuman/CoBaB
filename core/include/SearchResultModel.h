#ifndef SEARCHRESULTMODEL_H
#define SEARCHRESULTMODEL_H

#include <QAbstractListModel>
#include "SearchResult.h"
#include "SearchFeedback.h"

/**
 * @brief One-dimensional list model for SearchResult.
 * @author Vincent Winkler
 */
class SearchResultModel : public QAbstractListModel
{
public:
    SearchResultModel();
    void setSearchResult(const SearchResult* searchResult);
    SearchFeedback getFeedback() const;

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
    const SearchResult* mSearchResult;
    QMap<int, int> mFeedbacks;
};

#endif // SEARCHRESULTMODEL_H
