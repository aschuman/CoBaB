/**
 * Project \
 */


#include "..\..\include\CoBaB.h"
#include <QDir>
#include <QTextStream>
#include <algorithm>

/**
 * SingleFrameVideo implementation
 */

#define FRAMERATE_FILE "framerate.txt"
#define DEFAULT_FRAMERATE 24
#define VALID_FILE_TYPES "*.jpg|*.jpeg|*.bmp|*.png"

/**
 * @param path
 */
SingleFrameVideo::SingleFrameVideo(QString path, QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mMediumType = SINGLE_FRAME_VIDEO;

    QDir dir(mRelativePath);
    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Type);
    mFrameList = dir.entryList();
    QListIterator<QString> iterator(mFrameList);
    while (iterator.hasNext()) {
        QString file = iterator.next();
        if(file == FRAMERATE_FILE) {
            mFrameList.removeOne(file);
            QTextStream stream(file);
            QString framerate;
            stream >> framerate;
            bool *ok;
            mFramerate = framerate.toInt(ok, 10);
            if(!ok) {
                mFramerate = DEFAULT_FRAMERATE;
            }
            break;
        }
    }
    iterator.toFront();
    while(iterator.hasNext()) {
        QRegExp rx(VALID_FILE_TYPES);
        QString file = iterator.next();
        if(!rx.exactMatch(file)) {
            mFrameList.removeOne(file);
        }
    }

    struct {
            bool operator()(QPair<int, Annotation> a, QPair<int, Annotation> b)
            {
                return a.first < b.first;
            }
        } customLess;
        std::sort(mAnnotationList.begin(), mAnnotationList.end(), customLess);
        QListIterator<QPair<int, Annotation>> iter(mAnnotationList);
        iter.toBack();
        while(iter.hasPrevious()) {
            QPair<int, Annotation> pair = iter.previous();
            if(pair.first > mFrameList.size()) {
                mAnnotationList.removeOne(pair);
            } else {
                break;
            }
        }
}

/**
 * @return int
 */
int SingleFrameVideo::getFramerate() {
    return mFramerate;
}

/**
 * @return QList<QString>
 */
QList<QString> SingleFrameVideo::getFrameList() {
    return mFrameList;
}
