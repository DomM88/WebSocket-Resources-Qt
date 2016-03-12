/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef PROTOBUFWEBSOCKETMESSAGEFACTORY_H
#define PROTOBUFWEBSOCKETMESSAGEFACTORY_H

#include "../WebSocketMessageFactory.h"

class ProtobufWebSocketMessageFactory : public WebSocketMessageFactory
{
public:
    explicit ProtobufWebSocketMessageFactory();

    // WebSocketMessageFactory interface
public:
    QSharedPointer<WebSocketMessage> parseMessage(const QByteArray &serialized) Q_DECL_OVERRIDE;
    QSharedPointer<WebSocketMessage> createRequest(quint64 requestId, const QString &verb, const QString &path,
                                   const QByteArray &body) Q_DECL_OVERRIDE;
    QSharedPointer<WebSocketMessage> createResponse(quint64 requestId, quint32 status, const QString &message,
                                    const QByteArray &body) Q_DECL_OVERRIDE;
};

#endif // PROTOBUFWEBSOCKETMESSAGEFACTORY_H
