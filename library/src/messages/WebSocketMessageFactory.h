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

#include <QByteArray>

class WebSocketMessageFactory
{
public:
    WebSocketMessageFactory() {}
    virtual ~WebSocketMessageFactory() {}

    virtual WebSocketMessage parseMessage(const QByteArray &serialized) = 0;

    virtual WebSocketMessage createRequest(long requestId, const QString &verb,
                                           const QString &path, const QByteArray &body) = 0;

    virtual WebSocketMessage createResponse(long requestId, int status,
                                            const QString &message, const QByteArray &body) = 0;
};

#endif // WEBSOCKETMESSAGEFACTORY

