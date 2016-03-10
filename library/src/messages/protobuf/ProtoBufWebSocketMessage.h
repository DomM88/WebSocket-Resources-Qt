/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef PROTOBUFWEBSOCKETMESSAGE_H
#define PROTOBUFWEBSOCKETMESSAGE_H

#include <QScopedPointer>

#include "../WebSocketMessage.h"

namespace textsecure {
class WebSocketMessage;
}

class ProtoBufWebSocketMessage : public WebSocketMessage
{
public:
    ProtoBufWebSocketMessage(const QByteArray &buffer);
    ProtoBufWebSocketMessage(const textsecure::WebSocketMessage &websocketMessage);
    ~ProtoBufWebSocketMessage();

    // WebSocketMessage interface
    Type getType() Q_DECL_OVERRIDE;
    QSharedPointer<WebSocketRequestMessage> getRequestMessage() Q_DECL_OVERRIDE;
    QSharedPointer<WebSocketResponseMessage> getResponseMessage() Q_DECL_OVERRIDE;
    QByteArray toByteArray() Q_DECL_OVERRIDE;

private:
    QScopedPointer<textsecure::WebSocketMessage> m_message;
};

#endif // PROTOBUFWEBSOCKETMESSAGE_H
