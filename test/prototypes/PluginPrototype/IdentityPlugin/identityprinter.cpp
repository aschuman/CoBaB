#include "identityprinter.h"
#include <iostream>

template<typename T>
void IdentityPrinter<T>::print(const T &value)
{
    std::cout << value << std::endl;
}
