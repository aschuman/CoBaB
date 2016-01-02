#include "identityprinter.h"
#include <iostream>

//template<typename T>
void IdentityPrinter::print(const Greeting &value)
{
    std::cout << value.get().toStdString() << std::endl;
}
