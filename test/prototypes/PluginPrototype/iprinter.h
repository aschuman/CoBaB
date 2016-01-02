#ifndef IPRINTER_H
#define IPRINTER_H

template<typename T>
class IPrinter
{
public:
    virtual ~IPrinter() = default;
    virtual void print(const T& value) = 0;
};

// todo: see if there is a way to export a template class as plugin
#define IPrinter_iid "org.qt-project.Qt.Examples.EchoInterface"
template<typename T>
Q_DECLARE_INTERFACE(IPrinter<T>, IPrinter_iid)

#endif

