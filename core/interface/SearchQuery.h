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
    
    QList<Dataset>* getDatasets();

    void setDatasets(QList<Dataset>* datasets);
    
    SearchObject* getSearchObject();

    void setSearchObject(SearchObject* searchObject);
    
    friend QDataStream& operator<<(QDataStream& out, const SearchQuery& searchQuery);
    
    friend QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery);
    
    void toStream(QDataStream in) override;
    
    void fromStream(QDataStream out) override;

private:

    QList<QString>* mDatasets = new QList<QString>;

    SearchObject* mSearchObject = new SearchObject();

    QList<Dataset>* createDatasetList(QList<QString>* datasets);

};

#endif //_SEARCHQUERY_H
