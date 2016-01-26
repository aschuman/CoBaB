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

#endif // PAGETYPE

