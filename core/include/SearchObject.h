#ifndef SEARCHOBJECT_H
#define SEARCHOBJECT_H

#include "Dataset.h"
#include "Annotation.h"
#include "Medium.h"
#include "DataPacket.h"
#include <QRect>

class SearchObject: public Serializable {

public:

    SearchObject();
    QString getMedium();
    void setMedium(QString medium);
    Annotation getAnnotation();
    void setAnnotation(Annotation annotation);
    QRect getROI();
    void setROI(QRect roi);
    Dataset getSourceDataset();
    void setSourceDataset(Dataset dataset);
    int getMediumIndex();
    void setMediumIndex(int index);
    void toStream(QDataStream in);
    void fromStream(QDataStream out);

    friend QDataStream & operator >>(QDataStream &in, SearchObject &searchObject);
    friend QDataStream & operator <<(QDataStream &out, SearchObject &searchObject);

protected:

private:

    QString mMedium;
    Annotation mAnnotation;
    QRect mROI;
    QString mSourceDataset;
    int mMediumIndex;

};

#endif // SEARCHOBJECT_H
