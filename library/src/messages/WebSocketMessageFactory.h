/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef WEBSOCKETMESSAGEFACTORY
#define WEBSOCKETMESSAGEFACTORY

#include "WebSocketMessage.h"

#include <QSharedPointer>
#include <QByteArray>

class WebSocketMessageFactory
{
public:
    WebSocketMessageFactory() {}
    virtual ~WebSocketMessageFactory() {}

    virtual QSharedPointer<WebSocketMessage> parseMessage(const QByteArray &serialized) = 0;

    virtual QSharedPointer<WebSocketMessage> createRequest(quint64 requestId, const QString &verb,
                                           const QString &path, const QByteArray &body) = 0;

    virtual QSharedPointer<WebSocketMessage> createResponse(quint64 requestId, quint32 status,
                                            const QString &message, const QByteArray &body) = 0;
};

#endif // WEBSOCKETMESSAGEFACTORY

