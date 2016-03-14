/**
 * Project \
 */


#ifndef _SEARCHRESULTELEMENT_H
#define _SEARCHRESULTELEMENT_H

#include "Serializable.h"
#include "SearchObject.h"

/**
 * @brief The SearchResultElement class builds a search result element and sets its score according to the algorithm.
 * @author Violina
 */
class SearchResultElement: public Serializable {
public: 
    
    SearchResultElement();
    
    double getScore() const;

    void setScore(const double score);
    
    SearchObject getSearchObject() const;

    void setSearchObject(const SearchObject searchObject);

    friend QDataStream& operator<<(QDataStream& out, const SearchResultElement& searchResultElement);

    friend QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement);

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;

    static bool compareByScore(const SearchResultElement& A, const SearchResultElement& B);

private:

    double mScore;                  ///< The score of the searchresult
    SearchObject mSearchObject;     ///< The searchobject

};

#endif //_SEARCHRESULTELEMENT_H
