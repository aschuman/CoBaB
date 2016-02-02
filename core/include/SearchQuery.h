/**
 * Project \
 */


#ifndef _SEARCHQUERY_H
#define _SEARCHQUERY_H

#include "DataPacket.h"
#include "Dataset.h"
#include "SearchObject.h"


class SearchQuery: public DataPacket {

public: 
    
    SearchQuery();
    
    QList<Dataset> * getDatasets();
    
    /**
     * @param datasets
     */
    void setDatasets(QList<Dataset> *datasets);
    
    SearchObject *getSearchObject();
    
    /**
     * @param searchObject
     */
    void setSearchObject(SearchObject *searchObject);
    
    /**
     * @param out
     * @param searchQuery
     */
    friend QDataStream& operator<<(QDataStream& out, SearchQuery& searchQuery);
    
    /**
     * @param in
     * @param searchQuery
     */
    friend QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);

private:

    QList<QString> *mDatasets = new QList<QString>;
    SearchObject *mSearchObject = new SearchObject();
};

#endif //_SEARCHQUERY_H
