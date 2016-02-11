/**
 * Project \
 */


#ifndef _SEARCHFEEDBACK_H
#define _SEARCHFEEDBACK_H

#include "DataPacket.h"
#include "FeedbackType.h"
#include "SearchFeedback.h"
#include "SearchObject.h"
#include <QDataStream>


class SearchFeedback: public DataPacket {
public:

    SearchFeedback();

    SearchFeedback(FeedbackType type);
    
    QList<QPair<SearchObject, int>> getFeedbackList();

    void setFeedbackList(QList<QPair<SearchObject, int>> feedbackList);
    
    FeedbackType getFeedbackType();

    friend QDataStream& operator<<(QDataStream& out, SearchFeedback& feedback);
    
    friend QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback);

    void toStream(QDataStream in) override;

    void fromStream(QDataStream out) override;

private: 
    QList<QPair<SearchObject, int>> mFeedbackList;
    FeedbackType mType;
};

#endif //_SEARCHFEEDBACK_H
