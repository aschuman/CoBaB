/**
 * Project \
 */


#include "SearchResultElement.h"

/**
 * SearchResultElement implementation
 * @author Violina
 */

SearchResultElement::SearchResultElement() {

}

/**
 * @brief gets the score of the element
 * @return the score
 */
int SearchResultElement::getScore() {
    return mScore;
}

/**
 * @brief sets the score of the element
 * @param score to be set
 */
void SearchResultElement::setScore(int score) {
    mScore = score;
}

/**
 * @brief gets the searchobject
 * @return the searchobject
 */
SearchObject * SearchResultElement::getSearchObject() {
    return mSearchObject;
}

/**
 * @brief sets the searchobject
 * @param searchObject to be set
 */
void SearchResultElement::setSearchObject(SearchObject *searchObject) {
    mSearchObject = searchObject;
}

/**
 * @brief override << the operator
 * @param out - the datastream
 * @param SearchResultElement whose data will be sent
 * @return out - the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchResultElement& searchResultElement) {

    //write object to stream
    out << searchResultElement.mScore
        << *searchResultElement.mSearchObject;
    return out;
}

/**
 * @brief override >> the operator
 * @param in - the datastream
 * @param SearchResultElement to be changed
 * @return in - the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement) {
    //read object from stream

    int score;
    SearchObject *searchObject = new SearchObject();

    in >> score;
    searchResultElement.setScore(score);


    in >> *searchObject;
    searchResultElement.setSearchObject(searchObject);


    return in;
}

/**
 * @brief calls the << operator
 * @param in - the datastream
 */
void SearchResultElement::toStream(QDataStream in) {

    in << *this;
}

/**
 * @brief calls the >> operator
 * @param out - the datastream
 */
void SearchResultElement::fromStream(QDataStream out) {

    out >> *this;
}
