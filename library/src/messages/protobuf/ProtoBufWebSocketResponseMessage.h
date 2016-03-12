/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef PROTOBUFWEBSOCKETRESPONSEMESSAGE_H
#define PROTOBUFWEBSOCKETRESPONSEMESSAGE_H

#include "../WebSocketResponseMessage.h"

#include <QSharedPointer>

namespace textsecure {
class WebSocketResponseMessage;
}

class ProtoBufWebSocketResponseMessage : public WebSocketResponseMessage
{
public:
    explicit ProtoBufWebSocketResponseMessage();
    ProtoBufWebSocketResponseMessage(const textsecure::WebSocketResponseMessage &responseMessage);

    // WebSocketResponseMessage interface
    quint64 requestId() Q_DECL_OVERRIDE;
    quint32 status() Q_DECL_OVERRIDE;
    QString message() Q_DECL_OVERRIDE;
    QByteArray body() Q_DECL_OVERRIDE;

private:
    QSharedPointer<textsecure::WebSocketResponseMessage> m_message;
};

#endif // PROTOBUFWEBSOCKETRESPONSEMESSAGE_H
