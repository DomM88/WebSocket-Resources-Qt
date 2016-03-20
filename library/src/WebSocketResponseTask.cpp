/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */
#include "WebSocketResponseTask.h"

WebSocketResponseTask::WebSocketResponseTask(QObject *parent)
    : QObject(parent)
{

}

QSharedPointer<WebSocketResponseMessage> WebSocketResponseTask::responseMessage() const
{
    return m_responseMessage;
}

void WebSocketResponseTask::setResponseMessage(const QSharedPointer<WebSocketResponseMessage> &responseMessage)
{
    m_responseMessage = responseMessage;
}
