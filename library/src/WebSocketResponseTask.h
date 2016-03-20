/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */
#ifndef WEBSOCKETRESPONSETASK_H
#define WEBSOCKETRESPONSETASK_H

#include <QObject>
#include <QSharedPointer>

#include "messages/WebSocketResponseMessage.h"

class WebSocketResponseTask : public QObject
{
    Q_OBJECT
public:
    WebSocketResponseTask(QObject *parent = 0);

    QSharedPointer<WebSocketResponseMessage> responseMessage() const;
    void setResponseMessage(const QSharedPointer<WebSocketResponseMessage> &responseMessage);

private:
    QSharedPointer<WebSocketResponseMessage> m_responseMessage;
};

#endif // WEBSOCKETRESPONSETASK_H
