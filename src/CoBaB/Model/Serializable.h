/**
 * Project \
 */


#ifndef _SERIALIZABLE_H
#define _SERIALIZABLE_H

class Serializable {
public: 
    
    /**
     * Saves the serializable object in a file.
     * @param in The QDataStream has the file set as device.
     */
    virtual void toStream(QDataStream in);
    
    /**
     * Loads the serializable object from a file.
     * @param out The QDataStream has the file set as device.
     */
    virtual void fromStream(QDataStream out);
};

#endif //_SERIALIZABLE_H
