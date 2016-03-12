/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <SubProtocol.pb.h>

#include "ProtoBufWebSocketRequestMessage.h"

ProtoBufWebSocketRequestMessage::ProtoBufWebSocketRequestMessage()
    : m_message(new textsecure::WebSocketRequestMessage)
{
}

ProtoBufWebSocketRequestMessage::ProtoBufWebSocketRequestMessage(const textsecure::WebSocketRequestMessage &requestMessage)
    : m_message(new textsecure::WebSocketRequestMessage(requestMessage))
{
}

QString ProtoBufWebSocketRequestMessage::verb()
{
    return QString::fromStdString(m_message->verb());
}

QString ProtoBufWebSocketRequestMessage::path()
{
    return QString::fromStdString(m_message->path());
}

QByteArray ProtoBufWebSocketRequestMessage::body()
{
    if (m_message->has_body()) {
        return QByteArray::fromStdString(m_message->body());
    }
    return QByteArray();
}

quint64 ProtoBufWebSocketRequestMessage::requestId()
{
    return m_message->id();
}

bool ProtoBufWebSocketRequestMessage::hasRequestId()
{
    return m_message->has_id();
}

