#include "PersonAlgorithm.h"
#include <QCoreApplication>

/**
 * @brief PersonAlgorithm::PersonAlgorithm create new algorithm with given ID
 * @param id algorithm ID
 */
PersonAlgorithm::PersonAlgorithm() {
    mId = "personAlgo";
    mName = "PersonSearch";
    mDescription = "Searches for person annotations in photo dataset(s)";
    mSupportProgressInfo = false;
    mQuery = nullptr;
}

/**
 * @brief PersonAlgorithm::run start the search
 * @return a list of data packets containing results
 */
QList<DataPacket*> PersonAlgorithm::run() {
    QList<DataPacket*> list;
    SearchResult* result = new SearchResult();
    list.append(dynamic_cast<DataPacket*>(result));

    Annotation* searchAnno = mSearchObject.getAnnotation();

    for (QString& datasetPath : mQuery->getDatasets()) {
        Dataset dataset(datasetPath);

        for (Medium* medium : dataset.getMediaList()) {

            QCoreApplication::processEvents();
            if (mCancel) return list;

            Photo* photo = dynamic_cast<Photo*>(medium);

            SearchObject* object = new SearchObject();
            object->setMedium(photo->getPath());
            object->setSourceDataset(dataset.getPath());

            //calculate score
            int score = 0;
            for (auto pair : photo->getAnnotationList()) {
                Annotation* anno = pair.second;
                if ( (anno->getType() == Annotation::Type::PERSON)
                    && (anno->getId() == searchAnno->getId()) ) {
                    score = 10;
                    break;
                }
            }

            //new result element
            SearchResultElement* resultElement = new SearchResultElement();
            resultElement->setSearchObject(*object);
            resultElement->setScore(score);

            //add to result list
            result->addResultElement(*resultElement);
        }
    }

    return list;
}

/**
 * @brief PersonAlgorithm::setInputs set input for algorithm
 * @param inputDataList input data
 * @return true if input data is accepted
 */
bool PersonAlgorithm::setInputs(const QList<DataPacket*>& inputDataList) {
    //inputDataList can have 2 elements (with feedback)
    if ((inputDataList.length() != 1) && (inputDataList.length() != 2)) {  //illegal number of parameters
        return false;
    }

    DataPacket* packet = inputDataList.value(0);
    if (packet->getType() != DataPacket::Type::SEARCHQUERY) {   //invalid query
        return false;
    }

    mQuery = dynamic_cast<SearchQuery*>(packet);
    mSearchObject = mQuery->getSearchObject();

    //check if search object is annotation
    if (mSearchObject.getType() != SearchObject::Type::ANNOTATION) {
        return false;
    }

    //check if search annotation is of FACE type
    if (mSearchObject.getAnnotation()->getType() != Annotation::Type::PERSON) {
        return false;
    }

    //check if all search datasets are photo datasets
    for (QString& datasetPath : mQuery->getDatasets()) {
        Dataset dataset(datasetPath);
        if (dataset.getType() != Dataset::Type::PHOTO) {
            return false;
        }
    }

    return true;
}

