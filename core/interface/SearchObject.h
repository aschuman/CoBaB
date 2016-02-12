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

    Annotation* getAnnotation();

    void setAnnotation(Annotation *annotation);

    QRect* getROI();

    void setROI(QRect* roi);

    QString getSourceDataset();

    void setSourceDataset(QString dataset);

    int getMediumIndex();

    void setMediumIndex(int index);

    void toStream(QDataStream in) override;

    void fromStream(QDataStream out) override;

    friend QDataStream& operator >>(QDataStream& in, SearchObject& searchObject);

    friend QDataStream& operator <<(QDataStream& out, const SearchObject& searchObject);

protected:

private:

    QString mMedium = "";

    Annotation* mAnnotation = new Annotation("", "");

    QRect* mROI = new QRect();

    QString mSourceDataset = "";

    int mMediumIndex = 0;

};

#endif // SEARCHOBJECT_H
