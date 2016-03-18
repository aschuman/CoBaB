#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "DataPacket.h"
#include <QList>
#include <QJsonObject>
#include <QPluginLoader>

/**
 * @brief Algorithms which should be executed with CoBaB need to implement this interface.
 * @author Tung
 */

class Algorithm : public QObject {
    Q_OBJECT
public: 
    virtual ~Algorithm() = default;
    
    virtual bool setInputs(const QList<DataPacket*>& inputDataList) = 0;    ///< set input for algorithm
    
    virtual bool setParameters(const QJsonObject& parameters);

    virtual QString getId() const;

    virtual QString getName() const;

    virtual QString getDescription() const;

    QJsonObject getParameters();

    QJsonObject getDefaultParameters();

    bool initialize(QPluginLoader* loader);

public slots:
    virtual QList<DataPacket*> run() = 0;   ///< start the search

    virtual void cancel();

protected:
    QString mDescription = "";              ///< a QString that describes the algorithm
    QString mName = "";                     ///< algorithm name (must be unique)
    QString mId = "";                       ///< algorithm ID
    bool mCancel = false;                   ///< indicates whether the algorithm is cancelled
    QJsonObject mParameters;                ///< the current parameters for this algorithm
    QJsonObject mDefaultParameters;         ///< the QJsonObject parameter file for this algorithm
};

#define Algorithm_iid "org.CoBaB.Algorithm"
Q_DECLARE_INTERFACE(Algorithm, Algorithm_iid)

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<Algorithm>)


#endif //_ALGORITHM_H
