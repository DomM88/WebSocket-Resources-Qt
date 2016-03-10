/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef WEBSOCKETRESPONSEMESSAGE
#define WEBSOCKETRESPONSEMESSAGE

#include <QByteArray>
#include <QString>

class WebSocketResponseMessage
{
public:
    WebSocketResponseMessage() {}
    virtual ~WebSocketResponseMessage() {}

    virtual quint64 getRequestId() = 0;
    virtual quint32 getStatus() = 0;
    virtual QString getMessage() = 0;
    virtual QByteArray getBody() = 0;
};

#endif // WEBSOCKETRESPONSEMESSAGE

