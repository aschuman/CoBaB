#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "DataPacket.h"
#include <QList>
#include <QJsonObject>
#include <QPluginLoader>

/**
 * Algorithm interface
 * @author Tung
 */

class Algorithm : public QObject {
    Q_OBJECT
public: 
    virtual ~Algorithm() = default;
    
    virtual bool setInputs(const QList<DataPacket*>& inputDataList) = 0;
    
    virtual bool setParameters(const QJsonObject& parameters);

    virtual QString getId() const;

    virtual QString getName() const;

    virtual QString getDescription() const;

    QJsonObject getParameters();

    bool initialize(QPluginLoader* loader);

public slots:
    virtual QList<DataPacket*> run() = 0;

    virtual void cancel() = 0;

protected:
    QString mDescription = "";
    QString mName = "";
    QString mId = "";
    QJsonObject mParameters;
};

#define Algorithm_iid "org.CoBaB.Algorithm"
Q_DECLARE_INTERFACE(Algorithm, Algorithm_iid)

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<Algorithm>)


#endif //_ALGORITHM_H
