/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <SubProtocol.pb.h>

#include "ProtoBufWebSocketMessage.h"
#include "ProtobufWebSocketMessageFactory.h"

ProtobufWebSocketMessageFactory::ProtobufWebSocketMessageFactory()
{
}

QSharedPointer<WebSocketMessage> ProtobufWebSocketMessageFactory::parseMessage(const QByteArray &serialized)
{
    return QSharedPointer<WebSocketMessage>(new ProtoBufWebSocketMessage(serialized));
}

QSharedPointer<WebSocketMessage> ProtobufWebSocketMessageFactory::createRequest(quint64 requestId,
                                                                                const QString &verb,
                                                                                const QString &path,
                                                                                const QByteArray &body)
{
    textsecure::WebSocketRequestMessage *tsRequestMessage = new textsecure::WebSocketRequestMessage;
    tsRequestMessage->set_verb(verb.toStdString());
    tsRequestMessage->set_path(path.toStdString());

    if (requestId != 0) {
        tsRequestMessage->set_id(requestId);
    }

    if (!body.isEmpty()) {
        tsRequestMessage->set_body(body.toStdString());
    }

    textsecure::WebSocketMessage *tsMessage = new textsecure::WebSocketMessage;
    tsMessage->set_type(textsecure::WebSocketMessage_Type_REQUEST);
    tsMessage->set_allocated_request(tsRequestMessage);

    return QSharedPointer<WebSocketMessage>(new ProtoBufWebSocketMessage(tsMessage));
}

QSharedPointer<WebSocketMessage> ProtobufWebSocketMessageFactory::createResponse(quint64 requestId,
                                                                                 quint32 status,
                                                                                 const QString &message,
                                                                                 const QByteArray &body)
{
    textsecure::WebSocketResponseMessage *tsResponseMessage = new textsecure::WebSocketResponseMessage;
    tsResponseMessage->set_id(requestId);
    tsResponseMessage->set_status(status);
    tsResponseMessage->set_message(message.toStdString());

    if (!body.isEmpty()) {
        tsResponseMessage->set_body(body.toStdString());
    }

    textsecure::WebSocketMessage *tsMessage = new textsecure::WebSocketMessage;
    tsMessage->set_type(textsecure::WebSocketMessage_Type_RESPONSE);
    tsMessage->set_allocated_response(tsResponseMessage);

    return QSharedPointer<WebSocketMessage>(new ProtoBufWebSocketMessage(tsMessage));
}
