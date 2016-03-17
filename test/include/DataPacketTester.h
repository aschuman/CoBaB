#ifndef DATAPACKETTESTER_H
#define DATAPACKETTESTER_H

#include <QObject>
/**
 * @brief The DataPacketTester class
 * @author Violina
 */
class DataPacketTester : public QObject
{
    Q_OBJECT
private slots:

    void testUuid();
    void testType();
    void testStreamMethods();

};

#endif // DATAPACKETTESTER_H
