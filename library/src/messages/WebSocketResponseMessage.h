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

    virtual quint64 requestId() { return 0; }
    virtual quint32 status() { return 0; }
    virtual QString message() { return QStringLiteral(""); }
    virtual QByteArray body() { return QByteArray(); }
};

#endif // WEBSOCKETRESPONSEMESSAGE

