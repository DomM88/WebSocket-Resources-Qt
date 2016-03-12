/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <SubProtocol.pb.h>

#include "ProtoBufWebSocketMessage.h"
#include "ProtoBufWebSocketRequestMessage.h"
#include "ProtoBufWebSocketResponseMessage.h"

ProtoBufWebSocketMessage::ProtoBufWebSocketMessage(const QByteArray &buffer)
    : m_message(new textsecure::WebSocketMessage)
{
    m_message->ParseFromString(buffer.toStdString());

    if (type() == REQUEST_MESSAGE) {
        if (!m_message->request().has_verb() ||
                !m_message->request().has_path()) {
            setError(WebSocketMessageError(WebSocketMessageError::Error::WrongAttributes,
                                           "Missing required request attributes!"));
        }
    } else if (type() == RESPONSE_MESSAGE) {
        if (!m_message->response().has_id() ||
                !m_message->response().has_status() ||
                !m_message->response().has_message()) {
            setError(WebSocketMessageError(WebSocketMessageError::Error::WrongAttributes,
                                           "Missing required response attributes!"));
        }
    } else {
        setError(WebSocketMessageError(WebSocketMessageError::Error::Parse,
                 "Invalid message was parsed."));
    }
}

/*!
 * \brief ProtoBufWebSocketMessage::ProtoBufWebSocketMessage
 * This constructor takes ownership of plain message pointer.
 * \param websocketMessage
 */
ProtoBufWebSocketMessage::ProtoBufWebSocketMessage(textsecure::WebSocketMessage *websocketMessage)
    : m_message(websocketMessage)
{

}

ProtoBufWebSocketMessage::~ProtoBufWebSocketMessage()
{
}

WebSocketMessage::Type ProtoBufWebSocketMessage::type()
{
    if (m_message->type() == textsecure::WebSocketMessage_Type_REQUEST &&
            m_message->has_request()) {
        return WebSocketMessage::REQUEST_MESSAGE;
    } else if (m_message->type() == textsecure::WebSocketMessage_Type_RESPONSE &&
               m_message->has_response()) {
        return WebSocketMessage::RESPONSE_MESSAGE;
    } else {
        return WebSocketMessage::UNKNOWN_MESSAGE;
    }
}

QSharedPointer<WebSocketRequestMessage> ProtoBufWebSocketMessage::requestMessage()
{
    return QSharedPointer<WebSocketRequestMessage>(new ProtoBufWebSocketRequestMessage(m_message->request()));
}

QSharedPointer<WebSocketResponseMessage> ProtoBufWebSocketMessage::responseMessage()
{
    return QSharedPointer<WebSocketResponseMessage>(new ProtoBufWebSocketResponseMessage(m_message->response()));
}

QByteArray ProtoBufWebSocketMessage::toByteArray()
{
    return QByteArray::fromStdString(m_message->SerializeAsString());
}

