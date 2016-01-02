#ifndef IPRINTER_H
#define IPRINTER_H

class IPrinter
{
public:
    virtual ~IPrinter() = default;
};

#define IPrinter_iid "org.qt-project.Qt.Examples.EchoInterface"
Q_DECLARE_INTERFACE(IPrinter, IPrinter_iid)

#endif // IPRINTER_H

