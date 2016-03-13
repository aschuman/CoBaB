/**
 * Project \
 */


#include "SearchResultElement.h"


/**
 * @brief SearchResultElement::SearchResultElement
 */
SearchResultElement::SearchResultElement() {
    mScore = 0;
}

/**
 * @brief gets the score of the element
 * @return the score
 */
double SearchResultElement::getScore() const {
    return mScore;
}

/**
 * @brief sets the score of the element
 * @param score to be set
 */
void SearchResultElement::setScore(const double score) {
    mScore = score;
}

/**
 * @brief gets the searchobject
 * @return the searchobject
 */
SearchObject SearchResultElement::getSearchObject() const {
    return mSearchObject;
}

/**
 * @brief sets the searchobject
 * @param searchObject to be set
 */
void SearchResultElement::setSearchObject(const SearchObject searchObject) {
    mSearchObject = searchObject;
}

/**
 * @brief override << the operator
 * @param out the datastream
 * @param SearchResultElement whose data will be sent
 * @return out the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchResultElement& searchResultElement) {
    searchResultElement.toStream(out);
    return out;
}

/**
 * @brief override >> the operator
 * @param in the datastream
 * @param SearchResultElement to be changed
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement) {
    searchResultElement.fromStream(in);
    return in;
}

/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchResultElement::toStream(QDataStream& out) const {

    //write object to stream
    out << mScore
        << mSearchObject;
}

/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchResultElement::fromStream(QDataStream& in) {

    //read object from stream
    in >> mScore;
    in >> mSearchObject;


}
/**
 * @brief compareByScore compares 2 elements by score
 * @param A first element
 * @param B second element
 * @return true if A's score is smaller than B's
 */
bool SearchResultElement::compareByScore(const SearchResultElement& A, const SearchResultElement& B) {
    return (A.getScore() < B.getScore());
}
