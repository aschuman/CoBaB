/**
 * Project \
 */


#ifndef _SEARCHFEEDBACK_H
#define _SEARCHFEEDBACK_H

#include "QDataStream.h"
#include "DataPacket.h"


class SearchFeedback: public QDataStream, public DataPacket {
public: 
    
    /**
     * @param type
     */
    void SearchFeedback(FeedbackType type);
    
    QList<QPair<SearchObject; int>> getFeedbackList();
    
    /**
     * @param feedbackList
     */
    void setFeedbackList(QList<QPair<SearchObject; int>> feedbackList);
    
    FeedbackType getFeedbackType();
    
    /**
     * @param out
     * @param feedback
     */
    QDataStream& operator<<(QDataStream& out, Feedback& feedback);
    
    /**
     * @param in
     * @param feedback
     */
    QDataStream& operator>>(QDataStream& in, Feedback& feedback);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);
private: 
    QList<QPair<SearchObject; int>> mFeedbackList;
    FeedbackType mType;
};

#endif //_SEARCHFEEDBACK_H