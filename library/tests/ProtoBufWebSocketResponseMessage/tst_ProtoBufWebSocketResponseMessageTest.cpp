/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>
#include <QtTest>

class ProtoBufWebSocketResponseMessageTest : public QObject
{
    Q_OBJECT

public:
    ProtoBufWebSocketResponseMessageTest();

private Q_SLOTS:
    void testCase1();
};

ProtoBufWebSocketResponseMessageTest::ProtoBufWebSocketResponseMessageTest()
{
}

void ProtoBufWebSocketResponseMessageTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ProtoBufWebSocketResponseMessageTest)

#include "tst_ProtoBufWebSocketResponseMessageTest.moc"
