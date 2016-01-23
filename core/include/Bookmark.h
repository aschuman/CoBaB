/**
 * Project \
 */


#ifndef _BOOKMARK_H
#define _BOOKMARK_H

#include "Serializable.h"
#include "SearchResult.h"
#include "SearchQuery.h"
#include "SearchFeedback.h"
#include <QDateTime>
#include <QJsonObject>

class Bookmark: public Serializable {
public: 
    
    /**
     * @param result
     * @param algorithm
     * @param query
     */
    Bookmark(SearchResult result, QString algorithm, SearchQuery query);
    
    /**
     * @param out
     * @param bookmark
     */
    friend QDataStream& operator<<(QDataStream& out, Bookmark& bookmark);
    
    /**
     * @param in
     * @param bookmark
     */
    friend QDataStream& operator>>(QDataStream& in, Bookmark& bookmark);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);
    
    /**
     * @param feedback
     */
    void setFeedback(SearchFeedback feedback);
    
    SearchFeedback getFeedback();
    
    /**
     * @param name
     */
    void setName(QString name);
    
    QString getName();
    
    QDateTime getDate();
    
    QString getAlgorithm();
    
    SearchQuery getSearchQuery();
    
    SearchResult getSearchResult();
    
    QJsonObject getParameter();
private: 
    QString mName;
    QDateTime mDate;
    QString mAlgorithm;
    SearchQuery mSearchQuery;
    SearchResult mSearchResult;
    QJsonObject mParameter;
    SearchFeedback mSearchFeedback;
};

#endif //_BOOKMARK_H
