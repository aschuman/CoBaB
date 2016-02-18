#ifndef _SEARCHFEEDBACK_H
#define _SEARCHFEEDBACK_H

#include "DataPacket.h"
#include "SearchFeedback.h"
#include "SearchObject.h"
#include <QDataStream>
#include <QStringList>

/**
 * SearchFeedback implementation
 * @author Tung
 */

class SearchFeedback: public DataPacket {
public:

    enum Type { DUAL, EXTENDED };

    SearchFeedback();

    explicit SearchFeedback(QString& type);

    void setFeedbackList(QList<QPair<SearchObject, int>>& feedbackList);

    const QList<QPair<SearchObject, int>>& getFeedbackList();
    
    Type getType() const;

    friend QDataStream& operator<<(QDataStream& out, const SearchFeedback& feedback);
    
    friend QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback);

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;

private: 
    QList<QPair<SearchObject, int>> mFeedbackList;
    QString mType;      //type
};

#endif //_SEARCHFEEDBACK_H
