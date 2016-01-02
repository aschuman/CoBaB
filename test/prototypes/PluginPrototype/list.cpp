#include "list.h"

List::List(QList<QString> list) : mList(list)
{

}

size_t List::length() const
{
    return mList.size();
}


QString List::getLine(size_t index) const
{
    QString s;
    if(index < length())
        s = mList[index];
    return s;
}
