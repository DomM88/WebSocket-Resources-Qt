/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>
#include <QtTest>

class ProtobufWebSocketMessageFactoryTest : public QObject
{
    Q_OBJECT

public:
    ProtobufWebSocketMessageFactoryTest();

private Q_SLOTS:
    void testCase1();
};

ProtobufWebSocketMessageFactoryTest::ProtobufWebSocketMessageFactoryTest()
{
}

void ProtobufWebSocketMessageFactoryTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ProtobufWebSocketMessageFactoryTest)

#include "tst_ProtobufWebSocketMessageFactoryTest.moc"
