/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>
#include <QtTest>

#include <messages/WebSocketMessageError.h>

class WebSocketMessageErrorTest : public QObject
{
    Q_OBJECT

public:
    WebSocketMessageErrorTest();

private Q_SLOTS:
    void testDefault();
};

WebSocketMessageErrorTest::WebSocketMessageErrorTest()
{
}

void WebSocketMessageErrorTest::testDefault()
{
    WebSocketMessageError error;
    QVERIFY2(error.hasError() == false, "Error on default");

    error.setError(WebSocketMessageError::Error::Parse);
    QVERIFY2(error.hasError() == true, "No error on explicit set error");

    error.setText("hello");
    QVERIFY2(error.text() == "hello", "Text wasn't set");
}

QTEST_APPLESS_MAIN(WebSocketMessageErrorTest)

#include "tst_WebSocketMessageErrorTest.moc"
