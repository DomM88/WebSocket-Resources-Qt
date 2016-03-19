/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QDebug>
#include <QWebSocket>
#include <QWebSocketServer>

#include "WebSocketServer.h"

WebSocketServer::WebSocketServer(const QString &serverName, int port, QObject *parent)
    : QObject(parent)
    , m_webSocketServer(new QWebSocketServer(serverName, QWebSocketServer::NonSecureMode, this))
{
    if (m_webSocketServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Echoserver listening on port" << port;
        connect(m_webSocketServer.data(), &QWebSocketServer::newConnection,
                this, &WebSocketServer::onNewConnection);
        connect(m_webSocketServer.data(), &QWebSocketServer::closed,
                [this] {
            qWarning() << "Connection closed.";
        });
        connect(m_webSocketServer.data(), &QWebSocketServer::acceptError,
                [this] (QAbstractSocket::SocketError error) {
            qWarning() << "Connection error: " << error;
        });
    }
}

void WebSocketServer::onNewConnection()
{
    QWebSocket *pSocket = m_webSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived,
            this, &WebSocketServer::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived,
            this, &WebSocketServer::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected,
            this, &WebSocketServer::socketDisconnected);

    m_clients << pSocket;
}

void WebSocketServer::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    qDebug() << "Message received:" << message;
    if (pClient) {
        pClient->sendTextMessage(message);
    }
}

void WebSocketServer::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    qDebug() << "Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}

void WebSocketServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
