#ifndef DATASETTESTER_H
#define DATASETTESTER_H

#include <QObject>

/**
 * @brief The DatasetTester class Tests the Dataset class.
 */
class DatasetTester : public QObject
{
    Q_OBJECT
private slots:
    void testValid_data();
    void testValid();

    void testType_data();
    void testType();

    void testName_data();
    void testName();

    void testPreviewImage_data();
    void testPreviewImage();

    void testMediaList_data();
    void testMediaList();

    void testPath_data();
    void testPath();

    void testAnnotationsSFVideo();
    void testAnnotationsVideo();
    void testAnnotationsPhoto();

};

#endif // DATASETTESTER_H
