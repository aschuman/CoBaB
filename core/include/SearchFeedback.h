/**
 * Project \
 */


#ifndef _SEARCHFEEDBACK_H
#define _SEARCHFEEDBACK_H

#include "DataPacket.h"
#include "SearchFeedback.h"
#include "SearchObject.h"
#include <QDataStream>


class SearchFeedback: public DataPacket {
public:

    enum Type { DUAL, EXTENDED };

    SearchFeedback();

    SearchFeedback(Type type);
    
    QList<QPair<SearchObject, int>> getFeedbackList();

    void setFeedbackList(QList<QPair<SearchObject, int>> feedbackList);
    
    Type getType();

    friend QDataStream& operator<<(QDataStream& out, SearchFeedback& feedback);
    
    friend QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback);

    void toStream(QDataStream in) override;

    void fromStream(QDataStream out) override;

private: 
    QList<QPair<SearchObject, int>> mFeedbackList;
    Type mType;
};

#endif //_SEARCHFEEDBACK_H
