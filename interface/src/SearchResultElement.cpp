/**
 * Project \
 */


#include "SearchResultElement.h"


/**
 * @brief SearchResultElement::SearchResultElement Constructs a default SearchResultElement.
 */
SearchResultElement::SearchResultElement() {
    mScore = 0;
}

/**
 * @brief SearchResultElement::getScore Gets the score of the element.
 * @return the score
 */
double SearchResultElement::getScore() const {
    return mScore;
}

/**
 * @brief SearchResultElement::setScore Sets the score of the element.
 * @param score to be set
 */
void SearchResultElement::setScore(const double score) {
    mScore = score;
}

/**
 * @brief SearchResultElement::getSearchObject Gets the searchobject.
 * @return the searchobject
 */
SearchObject SearchResultElement::getSearchObject() const {
    return mSearchObject;
}

/**
 * @brief SearchResultElement::setSearchObject Sets the searchobject.
 * @param searchObject to be set
 */
void SearchResultElement::setSearchObject(const SearchObject searchObject) {
    mSearchObject = searchObject;
}

/**
 * @brief operator << Overrides the operator <<.
 * @param out the datastream
 * @param searchResultElement whose data will be sent
 * @return out the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchResultElement& searchResultElement) {
    searchResultElement.toStream(out);
    return out;
}

/**
 * @brief operator >> Overrides the operator >>.
 * @param in the datastream
 * @param searchResultElement to be changed
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement) {
    searchResultElement.fromStream(in);
    return in;
}

/**
 * @brief SearchResultElement::toStream Calls the << operator and writes the SearchResultElement to stream.
 * @param out the datastream
 */
void SearchResultElement::toStream(QDataStream& out) const {

    //write object to stream
    out << mScore
        << mSearchObject;
}

/**
 * @brief SearchResultElement::fromStream Calls the >> operator and reads the SearchResultElement from stream.
 * @param in the datastream
 */
void SearchResultElement::fromStream(QDataStream& in) {

    //read object from stream
    in >> mScore;
    in >> mSearchObject;


}

/**
 * @brief SearchResultElement::compareByScore Compares 2 search result elements by score.
 * @param A first element
 * @param B second element
 * @return true if A's score is smaller than B's
 */
bool SearchResultElement::compareByScore(const SearchResultElement& A, const SearchResultElement& B) {
    return (A.getScore() < B.getScore());
}
