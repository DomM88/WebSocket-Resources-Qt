/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <SubProtocol.pb.h>

#include "ProtoBufWebSocketResponseMessage.h"

ProtoBufWebSocketResponseMessage::ProtoBufWebSocketResponseMessage()
    : m_message(new textsecure::WebSocketResponseMessage)
{
}

ProtoBufWebSocketResponseMessage::ProtoBufWebSocketResponseMessage(const textsecure::WebSocketResponseMessage &responseMessage)
    : m_message(new textsecure::WebSocketResponseMessage(responseMessage))
{
}

quint64 ProtoBufWebSocketResponseMessage::getRequestId()
{
    return m_message->id();
}

quint32 ProtoBufWebSocketResponseMessage::getStatus()
{
    return m_message->status();
}

QString ProtoBufWebSocketResponseMessage::getMessage()
{
    return QString::fromStdString(m_message->message());
}

QByteArray ProtoBufWebSocketResponseMessage::getBody()
{
    if (m_message->has_body()) {
        return QByteArray::fromStdString(m_message->body());
    }
    return QByteArray();
}

