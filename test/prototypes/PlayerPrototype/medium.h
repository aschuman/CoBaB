#ifndef MEDIUM_H
#define MEDIUM_H
#include <qstring.h>
#include <qlist.h>
#include <qrect.h>

class Medium
{
public:
    class Annotation
    {
    public:
        Annotation(int frame, QRect rect);

    private:
        int frame;
        QRect rect;

    public:
        int getFrame() const;
        QRect getRect() const;
    };

    explicit Medium(QString file, QList<Annotation> annotations);
    virtual ~Medium() = default;

protected:
    QString file;
    QList<Annotation> annotations;
    
public:
    QString getFile() const;
    QList<Annotation>::const_iterator beginAnnotations() const;
    QList<Annotation>::const_iterator endAnnotatoins() const;
};

#endif // MEDIUM_H
