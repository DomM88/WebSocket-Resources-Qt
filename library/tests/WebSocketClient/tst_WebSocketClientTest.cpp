/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */
#include <QString>
#include <QtTest>
#include <QWebSocket>
#include "WebSocketServer.h"

#include <WebSocketClient.h>
#include <messages/protobuf/ProtobufWebSocketMessageFactory.h>

class WebSocketClientTest : public QObject
{
    Q_OBJECT

public:
    WebSocketClientTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();

private:
    QWebSocket *m_webSocket = nullptr;
    QSharedPointer<WebSocketMessageFactory> m_messageFactory;
    WebSocketClient *m_client = nullptr;
    WebSocketServer *m_webSocketServer = nullptr;
};

WebSocketClientTest::WebSocketClientTest()
{
}

void WebSocketClientTest::initTestCase()
{
    QString serverName("testserver");
    int testPort(23454);
    m_messageFactory = QSharedPointer<WebSocketMessageFactory>(new ProtobufWebSocketMessageFactory);
    m_webSocketServer = new WebSocketServer(serverName, testPort, this);
    m_webSocket = new QWebSocket;
    m_webSocket->setParent(this);
    m_client = new WebSocketClient(m_webSocket, m_messageFactory, this);
}

void WebSocketClientTest::cleanupTestCase()
{

}

void WebSocketClientTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(WebSocketClientTest)

#include "tst_WebSocketClientTest.moc"
