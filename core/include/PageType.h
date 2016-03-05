#ifndef PAGETYPE
#define PAGETYPE
#include <QMetaType>

/**
 * @brief Identifies a PageWidget class in context of the Navigator.
 * @author Vincent Winkler
 */
enum class PageType {
    NONE,
    LIBRARY,
    PHOTO_VIEWER,
    SINGLE_FRAME_VIDEO_VIEWER,
    VIDEO_VIEWER,
    PARAMETER,
    CONFIRMATION,
    RESULTS
};

Q_DECLARE_METATYPE(PageType)

/**
 * @brief Returns a string of the name of the given PageType.
 * @param type The PageType whose name will be returned.
 * @return The string of the name of type.
 * @author Vincent Winkler
 */
inline std::string to_String(PageType type){
    std::string r;
    switch(type){
    case PageType::NONE:
        r = "None";
        break;
    case PageType::LIBRARY:
        r = "Library";
        break;
    case PageType::PHOTO_VIEWER:
        r = "Photo Viewer";
        break;
    case PageType::SINGLE_FRAME_VIDEO_VIEWER:
        r = "Single Frame Video Viewer";
        break;
    case PageType::VIDEO_VIEWER:
        r = "Video Viewer";
        break;
    case PageType::PARAMETER:
        r = "Parameter";
        break;
    case PageType::CONFIRMATION:
        r = "Confirmation";
        break;
    case PageType::RESULTS:
        r = "Results";
        break;
    default:
        r = "unknown";
        break;
    }
    return r;
}

#endif // PAGETYPE

