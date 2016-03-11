#include "PageWidget.h"

/**
 * @brief PageWidget::getName
 * @return
 */
QString PageWidget::getName() {
    return tr(mName.toStdString().c_str());
}
