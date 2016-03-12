/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include "WebSocketMessage.h"

WebSocketMessage::Type WebSocketMessage::type()
{
    return UNKNOWN_MESSAGE;
}

QSharedPointer<WebSocketRequestMessage> WebSocketMessage::requestMessage()
{
    return QSharedPointer<WebSocketRequestMessage>();
}

QSharedPointer<WebSocketResponseMessage> WebSocketMessage::responseMessage()
{
    return QSharedPointer<WebSocketResponseMessage>();
}

QByteArray WebSocketMessage::toByteArray()
{
    return QByteArray();
}

bool WebSocketMessage::hasError() const
{
    return m_error.hasError();
}

WebSocketMessageError WebSocketMessage::getError() const
{
    return m_error;
}

void WebSocketMessage::setError(const WebSocketMessageError &error)
{
    m_error = error;
}
