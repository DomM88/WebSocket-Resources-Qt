/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>
#include <QtTest>

class WebSocketMessageErrorTest : public QObject
{
    Q_OBJECT

public:
    WebSocketMessageErrorTest();

private Q_SLOTS:
    void testCase1();
};

WebSocketMessageErrorTest::WebSocketMessageErrorTest()
{
}

void WebSocketMessageErrorTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(WebSocketMessageErrorTest)

#include "tst_WebSocketMessageErrorTest.moc"
