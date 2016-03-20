/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QWebSocket>

#include <messages/WebSocketResponseMessage.h>
#include <messages/WebSocketMessageFactory.h>

#include "WebSocketClient.h"
#include "WebSocketResponseTask.h"

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

/*!
 * \brief WebSocketClient::sendRequest
 * Returns a new WebSocketResponseTask for this request. The caller is responsible to delete the
 * object, if it isn't needed anymore.
 * \param verb
 * \param path
 * \param body
 * \return
 */
QPointer<WebSocketResponseTask> WebSocketClient::sendRequest(const QString &verb,
                                                               const QString &path,
                                                               const QByteArray &body)
{
    QPointer<WebSocketResponseTask> responseTask(new WebSocketResponseTask);

    if (!m_webSocket) {
        return responseTask;
    }

    quint64 requestId = generateRequestId();
    m_responseTasks.insert(requestId, responseTask);

    auto requestMessage = m_messageFactory->createRequest(requestId, verb, path, body);

    m_webSocket->sendBinaryMessage(requestMessage->toByteArray());
}

quint64 WebSocketClient::generateRequestId()
{
    std::uniform_int_distribution<quint64> m_numberGenerator;
    quint64 number = m_numberGenerator(m_randomGenerator);
    return number;
}

