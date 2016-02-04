#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H
#include <QWidget>
#include <QVariant>

class PageWidget : public QWidget
{
    Q_OBJECT
public:
    virtual void reset() = 0;

signals:
    void pushToStack(QVariant item);
    void readFromStack(size_t index, QVariant& value);
    void exit(int exitCode);
};

#endif // PAGEWIDGET_H
