#ifndef IDENTITYPRINTER_H
#define IDENTITYPRINTER_H
#include <qobject.h>
#include <greeting.h>
#include <printer.h>

//template<typename T>
class IdentityPrinter : public QObject, public Printer<Greeting>
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.cobab.test.PluginPrototype.IPrinter" "identityprinter.json")
    Q_INTERFACES(IPrinter)
public:
    virtual ~IdentityPrinter() = default;
    virtual void print(const Greeting& value) override;
};

#endif // IDENTITYPRINTER_H
