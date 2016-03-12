/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef WEBSOCKETMESSAGE
#define WEBSOCKETMESSAGE

#include <QByteArray>
#include <QSharedPointer>

#include "WebSocketMessageError.h"
#include "WebSocketRequestMessage.h"
#include "WebSocketResponseMessage.h"

class WebSocketMessage
{
public:
    WebSocketMessage() {}
    virtual ~WebSocketMessage() {}

    enum Type {
        UNKNOWN_MESSAGE,
        REQUEST_MESSAGE,
        RESPONSE_MESSAGE
    };

    virtual Type type();
    virtual QSharedPointer<WebSocketRequestMessage> requestMessage();
    virtual QSharedPointer<WebSocketResponseMessage> responseMessage();
    virtual QByteArray toByteArray();

    bool hasError() const;
    WebSocketMessageError getError() const;
    void setError(const WebSocketMessageError &error);

private:
    WebSocketMessageError m_error;
};

#endif // WEBSOCKETMESSAGE

