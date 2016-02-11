#ifndef PAGETYPE
#define PAGETYPE
#include <QMetaType>

enum class PageType {
    NONE,
    LIBRARY,
    VIEWER,
    PARAMETER,
    CONFIRMATION,
    RESULTS
};

Q_DECLARE_METATYPE(PageType)

inline std::string to_String(PageType type){
    std::string r;
    switch(type){
    case PageType::NONE:
        r = "None";
        break;
    case PageType::LIBRARY:
        r = "Library";
        break;
    case PageType::VIEWER:
        r = "Viewer";
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

