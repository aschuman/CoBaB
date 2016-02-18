/**
 * Project \
 */


#include "SearchResultElement.h"


/**
 * @brief SearchResultElement::SearchResultElement
 */
SearchResultElement::SearchResultElement() {
    mScore = 0;
    mSearchObject = new SearchObject();
}

/**
 * @brief gets the score of the element
 * @return the score
 */
int SearchResultElement::getScore() const {
    return mScore;
}

/**
 * @brief sets the score of the element
 * @param score to be set
 */
void SearchResultElement::setScore(const int score) {
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


}

/**
 * @brief override >> the operator
 * @param in the datastream
 * @param SearchResultElement to be changed
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement) {

}

/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchResultElement::toStream(QDataStream& in) const {

    //read object from stream

    int score;
    SearchObject searchObject;

    in >> score;
    this->setScore(score);


    in >> searchObject;
    this->setSearchObject(searchObject);

}

/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchResultElement::fromStream(QDataStream& out) {

    //write object to stream
    out << this->getScore()
        << this->getSearchObject();

}
/**
 * @brief compareByScore compares 2 elements by score
 * @param A first element
 * @param B second element
 * @return true if A is smaller than B
 */
bool compareByScore(SearchResultElement A, SearchResultElement B) {
    return (A.getScore() < B.getScore());
}
