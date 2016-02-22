#include "DataPacketTester.h"
#include "DataPacket.h"

#include <QtTest>

void DataPacketTester::testUuid()
{
    DataPacket data;
    QVERIFY(data.getUuid() != nullptr);

}

void DataPacketTester::testType()
{
    DataPacket data;
    QVERIFY(data.getType() == DataPacket::Type::UNKNOWN);
}

void DataPacketTester::testStreamMethods()
{
    DataPacket data;

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream in(&file); //serialize the data into the file
    in << data; //serialize the datapacket
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream out(&file); //read the data serialized from the file
    DataPacket newData;
    out >> newData; //extract the datapacket
    file.close();

    QCOMPARE(data.getUuid(), newData.getUuid());
    QCOMPARE(data.getType(), newData.getType());

}
