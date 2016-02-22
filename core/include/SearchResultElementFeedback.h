#ifndef SEARCHRESULTELEMENTFEEDBACK
#define SEARCHRESULTELEMENTFEEDBACK

#include <QImage>
#include <QObject>

/**
 * @brief Contains necessary data to display a search result with feedback.
 * @author Vincent Winkler
 */
struct SearchResultElementFeedback
{
    /**
     * @brief Image of this element.
     */
    QImage img;
    /**
     * @brief Feedback of this element.
     */
    int rating;
};

Q_DECLARE_METATYPE(SearchResultElementFeedback)

#endif // SEARCHRESULTELEMENTFEEDBACK

