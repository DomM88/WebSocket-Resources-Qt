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

#include <qscopedpointer.h>

namespace textsecure {
class WebSocketResponseMessage;
}

class ProtoBufWebSocketResponseMessage : public WebSocketResponseMessage
{
public:
    explicit ProtoBufWebSocketResponseMessage();
    ProtoBufWebSocketResponseMessage(const textsecure::WebSocketResponseMessage &responseMessage);

    // WebSocketResponseMessage interface
    quint64 getRequestId() Q_DECL_OVERRIDE;
    quint32 getStatus() Q_DECL_OVERRIDE;
    QString getMessage() Q_DECL_OVERRIDE;
    QByteArray getBody() Q_DECL_OVERRIDE;

private:
    QScopedPointer<textsecure::WebSocketResponseMessage> m_message;
};

#endif // PROTOBUFWEBSOCKETRESPONSEMESSAGE_H
