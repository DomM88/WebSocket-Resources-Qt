/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef PROTOBUFWEBSOCKETMESSAGE_H
#define PROTOBUFWEBSOCKETMESSAGE_H

#include <QSharedPointer>

#include "../WebSocketMessage.h"

namespace textsecure {
class WebSocketMessage;
}

class ProtoBufWebSocketMessage : public WebSocketMessage
{
public:
    ProtoBufWebSocketMessage(const QByteArray &buffer);
    ProtoBufWebSocketMessage(textsecure::WebSocketMessage *websocketMessage);
    ~ProtoBufWebSocketMessage();

    // WebSocketMessage interface
    Type type() Q_DECL_OVERRIDE;
    QSharedPointer<WebSocketRequestMessage> requestMessage() Q_DECL_OVERRIDE;
    QSharedPointer<WebSocketResponseMessage> responseMessage() Q_DECL_OVERRIDE;
    QByteArray toByteArray() Q_DECL_OVERRIDE;

private:
    QSharedPointer<textsecure::WebSocketMessage> m_message;
};

#endif // PROTOBUFWEBSOCKETMESSAGE_H
