#ifndef _SERIALIZABLE_H
#define _SERIALIZABLE_H

#include <QDataStream>

/**
 * @brief The Serializable class provides the function to serialize objects.
 * @author Anja
 */
class Serializable {
public:

    explicit Serializable();
    
    /**
     * Saves the serializable object in a file.
     * @param in The QDataStream has the file set as device.
     */
    virtual void toStream(QDataStream& out) const;
    
    /**
     * Loads the serializable object from a file.
     * @param out The QDataStream has the file set as device.
     */
    virtual void fromStream(QDataStream& in);


    friend QDataStream& operator<<(QDataStream& out, const Serializable& ser);

    friend QDataStream& operator>>(QDataStream& in, Serializable ser);
};

#endif //_SERIALIZABLE_H
