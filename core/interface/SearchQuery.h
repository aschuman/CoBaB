/**
 * Project \
 */


#ifndef _SEARCHQUERY_H
#define _SEARCHQUERY_H

#include "DataPacket.h"
#include "Dataset.h"
#include "SearchObject.h"

/**
 * @brief SearchQuery class
 * @author Georgi
 */
class SearchQuery: public DataPacket {

public: 
    
    SearchQuery();
    
    QList<QString> getDatasets() const;

    void setDatasets(const QList<QString> datasets);
    
    SearchObject getSearchObject() const;

    void setSearchObject(const SearchObject searchObject);
    
    friend QDataStream& operator<<(QDataStream& out, const SearchQuery& searchQuery);
    
    friend QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery);
    
    void toStream(QDataStream& in) const override;
    
    void fromStream(QDataStream& out) override;

private:

    QList<QString> mDatasets;          ///< The list of datasets

    SearchObject mSearchObject;        ///< The searchobject


};

#endif //_SEARCHQUERY_H
