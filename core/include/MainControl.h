#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <memory>
#include<qobject.h>
#include "Navigator.h"
#include "DatasetList.h"
#include "SearchManager.h"


/**
 * @brief Entry point of the core library of this program.
 * @author Vincent Winkler
 */
class MainControl : public QObject
{
    Q_OBJECT

public:
    MainControl();

public slots:
    void run();

signals:
    /**
     * @brief Emitted when the core has finished execution.
     */
    void finished();

private:
    void initNavigation();
    DatasetList findDatasets() const;


    std::unique_ptr<Navigator> mNavi;
    std::unique_ptr<SearchManager> mSearchManager;
};

#endif // MAINCONTROL_H
