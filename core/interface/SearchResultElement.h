/**
 * Project \
 */


#ifndef _SEARCHRESULTELEMENT_H
#define _SEARCHRESULTELEMENT_H

#include "Serializable.h"
#include "SearchObject.h"

/**
 * @brief SearchResultElement class
 * @author Violina
 */
class SearchResultElement: public Serializable {
public: 
    
    SearchResultElement();
    
    int getScore() const;

    void setScore(const int score);
    
    SearchObject getSearchObject() const;

    void setSearchObject(const SearchObject searchObject);

    friend QDataStream& operator<<(QDataStream& out, const SearchResultElement& searchResultElement);

    friend QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement);

    void toStream(QDataStream& in) const override;

    void fromStream(QDataStream& out) override;

    static bool compareByScore(SearchResultElement A, SearchResultElement B);

private:

    int mScore;     ///< The score of the searchresult

    SearchObject mSearchObject;     ///< The searchobject

};

#endif //_SEARCHRESULTELEMENT_H
