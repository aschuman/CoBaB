#ifndef CONCRETEPRINTERS
#define CONCRETEPRINTERS
#include <qobject.h>
#include "identityprinter.h"
#include "../greeting.h"

class GreetingIdentityPrinter : public QObject, IdentityPrinter<Greeting>
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.cobab.test.PluginPrototype.IPrinter" FILE "identityprinter.json")
    Q_INTERFACES(IPrinter<T>)
}

#endif // CONCRETEPRINTERS

