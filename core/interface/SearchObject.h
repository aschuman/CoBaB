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

    void toStream(QDataStream& in) const override;

    void fromStream(QDataStream& out) override;


private:

    QString mMedium;            ///< Medium as the serachobject

    Annotation mAnnotation;     ///< Annotation as the searchobject

    QRect mROI;                 ///< The annotation as rectangle with coordinates ("region of ineterest")

    QString mSourceDataset;     ///< The source dataset, where the searchobject is to be found

    int mMediumIndex;           ///< The index of the medium, which specifies if it is a video or photo

};

#endif // SEARCHOBJECT_H
