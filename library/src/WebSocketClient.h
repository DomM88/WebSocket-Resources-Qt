/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QFuture>
#include <QSharedPointer>

class QWebSocket;
class WebSocketMessageFactory;
class WebSocketResponseMessage;

class WebSocketClient : public QObject
{
public:
    WebSocketClient(QWebSocket *webSocket, QSharedPointer<WebSocketMessageFactory> messageFactory,
                    QObject *parent=0);

    QWebSocket *webSocket() const;
    void setWebSocket(QWebSocket *webSocket);

    QFuture<WebSocketResponseMessage> sendRequest(const QString &verb, const QString &path, const QByteArray &body);

private:
    std::mt19937_64 m_randomGenerator;
    quint64 generateRequestId();
    QWebSocket *m_webSocket = nullptr;
    QSharedPointer<WebSocketMessageFactory> m_messageFactory;
};

#endif // WEBSOCKETCLIENT_H
