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

    virtual QString verb() = 0;
    virtual QString path() = 0;
    virtual QByteArray body() = 0;
    virtual quint64 requestId() = 0;
    virtual bool hasRequestId() = 0;
};

#endif // WEBSOCKETREQUESTMESSAGE

