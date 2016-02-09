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
    
    /**
     * @param type
     */
    SearchFeedback(FeedbackType type);
    
    QList<QPair<SearchObject, int>> getFeedbackList();
    
    /**
     * @param feedbackList
     */
    void setFeedbackList(QList<QPair<SearchObject, int>> feedbackList);
    
    FeedbackType getFeedbackType();
    
    /**
     * @param out
     * @param feedback
     */
    friend QDataStream& operator<<(QDataStream& out, SearchFeedback& feedback);
    
    /**
     * @param in
     * @param feedback
     */
    friend QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);
private: 
    QList<QPair<SearchObject, int>> mFeedbackList;
    FeedbackType mType;
};

#endif //_SEARCHFEEDBACK_H
