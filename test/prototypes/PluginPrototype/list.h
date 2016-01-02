#ifndef LIST_H
#define LIST_H
#include <qlist.h>
#include <qstring.h>


class List
{
    QList<QString> mList;
public:
    List(QList<QString> list);
    QString getLine(size_t index) const;
    size_t length() const;
};

#endif // LIST_H
