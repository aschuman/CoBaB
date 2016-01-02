#ifndef GREETING_H
#define GREETING_H
#include <qstring.h>

class Greeting
{
    QString mSubject;
public:
    Greeting(QString subject);
    QString get() const;
};

#endif // GREETING_H
