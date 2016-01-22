/**
 * Project \
 */


#ifndef _SEARCHRESULTELEMENT_H
#define _SEARCHRESULTELEMENT_H

#include "..\..\include\Serializable.h"
#include "..\..\include\SearchObject.h"


class SearchResultElement: public Serializable {
public: 
    
    SearchResultElement();
    
    int getScore();
    
    /**
     * @param score
     */
    void setScore(int score);
    
    SearchObject getSearchObject();
    
    /**
     * @param searchObject
     */
    void setSearchObject(SearchObject searchObject);
    
    /**
     * @param out
     * @param searchResultElement
     */
    QDataStream& operator<<(QDataStream& out, SearchResultElement& searchResultElement);
    
    /**
     * @param in
     * @param searchResultElement
     */
    QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);
private: 
    int mScore;
    SearchObject mSearchObject;
};

#endif //_SEARCHRESULTELEMENT_H
