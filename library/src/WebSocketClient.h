/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QHash>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>

class QWebSocket;
class WebSocketMessageFactory;
class WebSocketResponseMessage;
class WebSocketResponseTask;

class WebSocketClient : public QObject
{
public:
    WebSocketClient(QWebSocket *webSocket, QSharedPointer<WebSocketMessageFactory> messageFactory,
                    QObject *parent=0);

    QWebSocket *webSocket() const;
    void setWebSocket(QWebSocket *webSocket);

    QPointer<WebSocketResponseTask> sendRequest(const QString &verb, const QString &path, const QByteArray &body);

private:
    std::mt19937_64 m_randomGenerator;
    quint64 generateRequestId();
    QWebSocket *m_webSocket = nullptr;
    QSharedPointer<WebSocketMessageFactory> m_messageFactory;
    QHash<quint64, QPointer<WebSocketResponseTask>> m_responseTasks;
};

#endif // WEBSOCKETCLIENT_H
