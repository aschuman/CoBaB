/**
 * Project \
 */


#ifndef _ALGORITHMLIST_H
#define _ALGORITHMLIST_H

class AlgorithmList {
public: 
    
    /**
     * @param file
     */
    void AlgorithmList(QString file);
    
    /**
     * @param packet
     */
    QList<Algorithm> findCompatibleAlgorithms(DataPacket packet);
    
    QList<Algorithm> getAlgorithmList();
private: 
    QList<Algorithm> mAlgorithmList;
};

#endif //_ALGORITHMLIST_H