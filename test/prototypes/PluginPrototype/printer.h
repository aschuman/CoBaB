#ifndef PRINTER_H
#define PRINTER_H
#include "iprinter.h"

template<typename T>
class Printer : public IPrinter
{
public:
    virtual ~Printer() = default;
    virtual void print(const T& value) = 0;
};

#endif

