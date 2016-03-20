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
#include <QSignalSpy>
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
    void testSendRequest();

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
    connect(m_webSocket, &QWebSocket::connected,
            [this] { qDebug() << "Socket connected.";});
    connect(m_webSocket, static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error),
            [=](QAbstractSocket::SocketError error){ qWarning() << "Socket error: " << error; });

    QSignalSpy openSpy(m_webSocket, SIGNAL(connected()));
    m_webSocket->open(QUrl::fromUserInput(QString("ws://localhost:%1").arg(testPort)));
    openSpy.wait();

    QVERIFY2(m_webSocket->isValid(), "Socket not valid");

    m_client = new WebSocketClient(m_webSocket, m_messageFactory, this);
}

void WebSocketClientTest::cleanupTestCase()
{
    QSignalSpy closeSpy(m_webSocket, SIGNAL(disconnected()));
    m_webSocket->close();
    closeSpy.wait(1000);
}

void WebSocketClientTest::testSendRequest()
{
    m_client->sendRequest("GET", "/hello", "a23466ff5654d1243");
    QSignalSpy receiveSpy(m_webSocket, SIGNAL(binaryMessageReceived(QByteArray)));
    receiveSpy.wait();
}

QTEST_MAIN(WebSocketClientTest)

#include "tst_WebSocketClientTest.moc"
