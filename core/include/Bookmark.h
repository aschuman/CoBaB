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
#include <QJsonDocument>

class Bookmark: public Serializable {
public: 
    Bookmark();
    
    Bookmark(SearchResult result, QString algorithm, SearchQuery query);
    
    friend QDataStream& operator<<(QDataStream& out, const Bookmark& bookmark);

    friend QDataStream& operator>>(QDataStream& in, Bookmark& bookmark);
    
    void toStream(QDataStream& in) const override;
    
    void fromStream(QDataStream& out) override;

    void setFeedback(SearchFeedback feedback);
    
    SearchFeedback getFeedback();
       
    void setName(QString name);
    
    QString getName() const;
    
    QDateTime getDate() const;
    
    QString getAlgorithm();
    
    SearchQuery getSearchQuery();
    
    SearchResult getSearchResult();
    
    QJsonObject getParameter();

    friend bool operator==(const Bookmark& A, const Bookmark& B);

    static bool compareByName(Bookmark A, Bookmark B);

    static bool compareByDate(Bookmark A, Bookmark B);

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
