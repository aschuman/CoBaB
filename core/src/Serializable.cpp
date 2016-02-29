#include "Serializable.h"

Serializable::Serializable() {

}

void Serializable::toStream(QDataStream &out) const {
    //write object to stream
    out << *this;
}

void Serializable::fromStream(QDataStream &in) {
    //read object from stream
    in >> *this;
}

QDataStream& operator<<(QDataStream& out, const Serializable& ser) {
    ser.toStream(out);
    return out;
}

QDataStream& operator>>(QDataStream& in, Serializable& ser) {
    ser.fromStream(in);
    return in;
}
