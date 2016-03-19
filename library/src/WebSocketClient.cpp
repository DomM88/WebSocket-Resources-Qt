/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <messages/WebSocketResponseMessage.h>

#include "WebSocketClient.h"

WebSocketClient::WebSocketClient(QWebSocket *webSocket, QSharedPointer<WebSocketMessageFactory> messageFactory,
                                 QObject *parent)
    : QObject(parent),
      m_webSocket(webSocket),
      m_messageFactory(messageFactory)
{
    std::random_device rd;
    m_randomGenerator = std::mt19937_64(rd());

      /* This is where you define the number generator for unsigned long long: */
      std::uniform_int_distribution<unsigned long long> dis;

}

QWebSocket *WebSocketClient::webSocket() const
{
    return m_webSocket;
}

void WebSocketClient::setWebSocket(QWebSocket *webSocket)
{
    m_webSocket = webSocket;
}

QFuture<WebSocketResponseMessage> WebSocketClient::sendRequest(const QString &verb,
                                                               const QString &path,
                                                               const QByteArray &body)
{
    quint64 requestId = generateRequestId();
}

quint64 WebSocketClient::generateRequestId()
{
    std::uniform_int_distribution<quint64> m_numberGenerator;
    quint64 number = m_numberGenerator(m_randomGenerator);
    return number;
}

