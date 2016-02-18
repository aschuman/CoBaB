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

    Bookmark(const QString& path);
    
    Bookmark(const SearchResult& result, const QString& algorithm, const SearchQuery& query);

    void setFeedback(const SearchFeedback& feedback);

    void setName(const QString& name);

    void setParameter(const QJsonObject& parameter);
    
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

    void save(const QString path);

    void deleteFile() const;

    friend QDataStream& operator<<(QDataStream& out, const Bookmark& bookmark);

    friend QDataStream& operator>>(QDataStream& in, Bookmark& bookmark);

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;

private: 
    QString mPath;
    QString mName;
    QDateTime mDate;
    QString mAlgorithm;
    SearchQuery mSearchQuery;
    SearchResult mSearchResult;
    QJsonObject mParameter;
    SearchFeedback mSearchFeedback;
};

#endif //_BOOKMARK_H
