/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */
#include <QString>
#include <QtTest>

#include <WebSocketResponseTask.h>

class WebSocketResponseTaskTest : public QObject
{
    Q_OBJECT

public:
    WebSocketResponseTaskTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

WebSocketResponseTaskTest::WebSocketResponseTaskTest()
{
}

void WebSocketResponseTaskTest::initTestCase()
{
}

void WebSocketResponseTaskTest::cleanupTestCase()
{
}

void WebSocketResponseTaskTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(WebSocketResponseTaskTest)

#include "tst_WebSocketResponseTaskTest.moc"
