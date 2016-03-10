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

#include <QScopedPointer>

namespace textsecure {
class WebSocketRequestMessage;
}

class ProtoBufWebSocketRequestMessage : public WebSocketRequestMessage
{
public:
    explicit ProtoBufWebSocketRequestMessage();
    ProtoBufWebSocketRequestMessage(const textsecure::WebSocketRequestMessage &requestMessage);

    // WebSocketRequestMessage interface
    QString getVerb() Q_DECL_OVERRIDE;
    QString getPath() Q_DECL_OVERRIDE;
    QByteArray getBody() Q_DECL_OVERRIDE;
    quint64 getRequestId() Q_DECL_OVERRIDE;
    bool hasRequestId() Q_DECL_OVERRIDE;

private:
    QScopedPointer<textsecure::WebSocketRequestMessage> m_message;
};

#endif // PROTOBUFWEBSOCKETREQUESTMESSAGE_H
