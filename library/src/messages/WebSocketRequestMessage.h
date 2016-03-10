/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#ifndef WEBSOCKETREQUESTMESSAGE
#define WEBSOCKETREQUESTMESSAGE

#include <QByteArray>
#include <QString>

class WebSocketRequestMessage
{
public:
    WebSocketRequestMessage() {}
    virtual ~WebSocketRequestMessage() {}

    virtual QString getVerb() = 0;
    virtual QString getPath() = 0;
    virtual QByteArray getBody() = 0;
    virtual quint64 getRequestId() = 0;
    virtual bool hasRequestId() = 0;
};

#endif // WEBSOCKETREQUESTMESSAGE

