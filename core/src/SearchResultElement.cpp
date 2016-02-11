/**
 * Project \
 */


#include "SearchResultElement.h"

/**
 * SearchResultElement implementation
 */

SearchResultElement::SearchResultElement() {

}

/**
 * @return int
 */
int SearchResultElement::getScore() {
    return mScore;
}

/**
 * @param score
 */
void SearchResultElement::setScore(int score) {
    mScore = score;
}

/**
 * @return SearchObject
 */
SearchObject * SearchResultElement::getSearchObject() {
    return mSearchObject;
}

/**
 * @param searchObject
 */
void SearchResultElement::setSearchObject(SearchObject *searchObject) {
    mSearchObject = searchObject;
}

/**
 * @param out
 * @param searchResultElement
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, SearchResultElement& searchResultElement) {

    //write object to stream
    out << "(" << searchResultElement.getScore() <<
        ", " << searchResultElement.getSearchObject() << ")";
    return out;
}

/**
 * @param in
 * @param searchResultElement
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement) {
    //read object from stream

    int score;
    SearchObject *searchObject = new SearchObject();

    //skip opening bracket
    in.skipRawData(1);

    in >> score;
    searchResultElement.setScore(score);

    //skip coma
    in.skipRawData(2);

    in >> *searchObject;
    searchResultElement.setSearchObject(searchObject);

    in.skipRawData(1);

    return in;
}

/**
 * @param in
 */
void SearchResultElement::toStream(QDataStream in) {

    in << *this;
}

/**
 * @param out
 */
void SearchResultElement::fromStream(QDataStream out) {

    out >> *this;
}
