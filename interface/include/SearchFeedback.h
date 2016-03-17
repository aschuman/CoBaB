#ifndef _SEARCHFEEDBACK_H
#define _SEARCHFEEDBACK_H

#include "DataPacket.h"
#include "SearchObject.h"
#include <QDataStream>
#include <QStringList>

/**
 * @brief SearchFeedback Specifies the quality of the result of the SearchResult.
 * @author Tung
 */

class SearchFeedback: public DataPacket {
public:

    /**
     * @brief The Type enum SearchFeedback can be dual or extended
     */
    enum Type { DUAL, EXTENDED };

    SearchFeedback();

    explicit SearchFeedback(const QString& type);

    void setFeedbackList(const QList<QPair<SearchObject, int>>& feedbackList);

    const QList<QPair<SearchObject, int>>& getFeedbackList() const;
    
    Type getFeedbackType() const;

    friend QDataStream& operator<<(QDataStream& out, const SearchFeedback& feedback);
    
    friend QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback);

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;

private: 
    QList<QPair<SearchObject, int>> mFeedbackList;
    QString mFeedbackType;      //feedback type
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<SearchFeedback>)

#endif //_SEARCHFEEDBACK_H
