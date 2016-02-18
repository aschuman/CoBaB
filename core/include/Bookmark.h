#ifndef _BOOKMARK_H
#define _BOOKMARK_H

#include "Serializable.h"
#include "SearchResult.h"
#include "SearchQuery.h"
#include "SearchFeedback.h"
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>

/**
 * Bookmark implementation
 * @author Tung
 */

class Bookmark: public Serializable {
public: 
    Bookmark();
    
    Bookmark(SearchResult& result, QString& algorithm, SearchQuery& query);

    void setFeedback(SearchFeedback& feedback);

    void setName(QString& name);

    void setParameter(QJsonObject& parameter);
    
    QString getName() const;
    
    QDateTime getDate() const;
    
    QString getAlgorithm() const;

    QJsonObject getParameter() const;
    
    const SearchQuery& getSearchQuery() const;
    
    const SearchResult& getSearchResult() const;

    const SearchFeedback& getFeedback() const;

    friend bool operator==(const Bookmark& A, const Bookmark& B);

    static bool smallerByName(const Bookmark& A, const Bookmark& B);

    static bool smallerByDate(const Bookmark& A, const Bookmark& B);

    static bool validate(const Bookmark& bookmark);

    void load(QString path);

    void save(QString path) const;

    friend QDataStream& operator<<(QDataStream& out, const Bookmark& bookmark);

    friend QDataStream& operator>>(QDataStream& in, Bookmark& bookmark);

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;

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
