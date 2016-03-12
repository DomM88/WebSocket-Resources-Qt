/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>
#include <QtTest>

class ProtoBufWebSocketRequestMessageTest : public QObject
{
    Q_OBJECT

public:
    ProtoBufWebSocketRequestMessageTest();

private Q_SLOTS:
    void testCase1();
};

ProtoBufWebSocketRequestMessageTest::ProtoBufWebSocketRequestMessageTest()
{
}

void ProtoBufWebSocketRequestMessageTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ProtoBufWebSocketRequestMessageTest)

#include "tst_ProtoBufWebSocketRequestMessageTest.moc"
