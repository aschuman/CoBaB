/**
 * Project \
 */


#ifndef _ALGORITHM_H
#define _ALGORITHM_H

class Algorithm {
public: 
    
    QList<DataPacket> run();
    
    void cancel();
    
    /**
     * @param inputDataList
     */
    bool setInputs(QList<DataPacket> inputDataList);
    
    /**
     * @param parameters
     */
    bool setParameters(QJsonObject parameters);
    
    QString getId();
};

#endif //_ALGORITHM_H