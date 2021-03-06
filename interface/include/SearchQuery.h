/**
 * Project \
 */


#ifndef _SEARCHQUERY_H
#define _SEARCHQUERY_H

#include "DataPacket.h"
#include "Dataset.h"
#include "SearchObject.h"

/**
 * @brief The SearchQuery class builds a search query with the given searchobject and the datasets to be searched from.
 * @author Georgi
 */
class SearchQuery: public DataPacket {

public: 
    
    SearchQuery();
    
    QList<QString> getDatasets() const;

    void setDatasets(const QList<QString> datasets);
    
    SearchObject getSearchObject() const;

    void setSearchObject(const SearchObject& searchObject);
    
    friend QDataStream& operator<<(QDataStream& out, const SearchQuery& searchQuery);
    
    friend QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery);
    
    void toStream(QDataStream& out) const override;
    
    void fromStream(QDataStream& in) override;

private:

    QList<QString> mDatasets;          ///< The list of datasets

    SearchObject mSearchObject;        ///< The searchobject


};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<SearchQuery>)

#endif //_SEARCHQUERY_H
