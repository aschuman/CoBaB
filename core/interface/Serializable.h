#ifndef _SERIALIZABLE_H
#define _SERIALIZABLE_H

#include <QDataStream>

/**
 * @brief The Serializable class provides the function to serialize objects.
 * @author Anja
 */
class Serializable {
public: 
    
    /**
     * Saves the serializable object in a file.
     * @param in The QDataStream has the file set as device.
     */
    virtual void toStream(QDataStream& in) = 0;
    
    /**
     * Loads the serializable object from a file.
     * @param out The QDataStream has the file set as device.
     */
    virtual void fromStream(QDataStream& out) = 0;
};

#endif //_SERIALIZABLE_H
