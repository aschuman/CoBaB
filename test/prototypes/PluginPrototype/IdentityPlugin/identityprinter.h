#ifndef IDENTITYPRINTER_H
#define IDENTITYPRINTER_H
#include <qobject.h>
#include "../iprinter.h"

template<typename T>
class IdentityPrinter : public IPrinter<T>
{
    virtual void print(const T& value) override;
};

#endif // IDENTITYPRINTER_H
