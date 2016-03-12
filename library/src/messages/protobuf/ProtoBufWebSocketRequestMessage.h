/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef PROTOBUFWEBSOCKETREQUESTMESSAGE_H
#define PROTOBUFWEBSOCKETREQUESTMESSAGE_H

#include "../WebSocketRequestMessage.h"

#include <QSharedPointer>

namespace textsecure {
class WebSocketRequestMessage;
}

class ProtoBufWebSocketRequestMessage : public WebSocketRequestMessage
{
public:
    explicit ProtoBufWebSocketRequestMessage();
    ProtoBufWebSocketRequestMessage(const textsecure::WebSocketRequestMessage &requestMessage);

    // WebSocketRequestMessage interface
    QString verb() Q_DECL_OVERRIDE;
    QString path() Q_DECL_OVERRIDE;
    QByteArray body() Q_DECL_OVERRIDE;
    quint64 requestId() Q_DECL_OVERRIDE;
    bool hasRequestId() Q_DECL_OVERRIDE;

private:
    QSharedPointer<textsecure::WebSocketRequestMessage> m_message;
};

#endif // PROTOBUFWEBSOCKETREQUESTMESSAGE_H
