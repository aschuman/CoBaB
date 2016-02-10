/**
 * Project \
 */


#ifndef _SEARCHRESULTELEMENT_H
#define _SEARCHRESULTELEMENT_H

#include "Serializable.h"
#include "SearchObject.h"


class SearchResultElement: public Serializable {
public: 
    
    SearchResultElement();
    
    int getScore();

    void setScore(int score);
    
    SearchObject* getSearchObject();

    void setSearchObject(SearchObject* searchObject);

    friend QDataStream& operator<<(QDataStream& out, SearchResultElement& searchResultElement);

    friend QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement);

    void toStream(QDataStream in);

    void fromStream(QDataStream out);

private:

    int mScore;

    SearchObject* mSearchObject;

};

#endif //_SEARCHRESULTELEMENT_H
