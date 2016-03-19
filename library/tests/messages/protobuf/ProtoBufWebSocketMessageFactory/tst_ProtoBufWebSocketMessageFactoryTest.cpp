/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>
#include <QtTest>

class ProtoBufWebSocketMessageFactoryTest : public QObject
{
    Q_OBJECT

public:
    ProtoBufWebSocketMessageFactoryTest();

private Q_SLOTS:
    void testCase1();
};

ProtoBufWebSocketMessageFactoryTest::ProtoBufWebSocketMessageFactoryTest()
{
}

void ProtoBufWebSocketMessageFactoryTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ProtoBufWebSocketMessageFactoryTest)

#include "tst_ProtoBufWebSocketMessageFactoryTest.moc"
