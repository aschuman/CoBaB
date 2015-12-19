#ifndef MEDIUM_H
#define MEDIUM_H
#include <qstring.h>

class Medium
{
public:
    explicit Medium(const QString& file);
    virtual ~Medium() = default;

protected:
    QString file;
    
};

#endif // MEDIUM_H
