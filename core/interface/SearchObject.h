#ifndef SEARCHOBJECT_H
#define SEARCHOBJECT_H

#include "Dataset.h"
#include "Annotation.h"
#include "Medium.h"
#include "DataPacket.h"
#include <QRect>


/**
 * @brief A SearchObject is a medium or annotation, on which the searchalgorithm operates
 * @author Georgi
 */
class SearchObject: public Serializable {

public:

    enum Type { MEDIUM, ROI, ANNOTATION };

    SearchObject();

    QString getMedium() const;

    void setMedium(const QString medium);

    Annotation getAnnotation() const;

    void setAnnotation(const Annotation annotation);

    QRect getROI() const;

    void setROI(const QRect roi);

    QString getSourceDataset() const;

    void setSourceDataset(const QString dataset);

    int getMediumIndex() const;

    void setMediumIndex(const int index);

    Type getType() const;

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;

 //   friend QDataStream& operator<<(QDataStream& out, const SearchObject& searchObject);

   // friend QDataStream& operator>>(QDataStream& in, SearchObject& searchObject);

private:

    QString mMedium;            ///< Medium as the searchobject

    Annotation mAnnotation;     ///< Annotation as the searchobject

    QRect mROI;                 ///< The annotation as rectangle with coordinates ("region of interest")

    QString mSourceDataset;     ///< The source dataset, where the searchobject is to be found

    int mMediumIndex;           ///< The index of the medium, which specifies if it is a video or photo

    Type mType;                 ///< The type of the searchobject

};

#endif // SEARCHOBJECT_H
