#include "identityprinter.h"
#include <iostream>

void IdentityPrinter::print(const Greeting& value)
{
    std::cout << value.get().toStdString() << std::endl;
}
