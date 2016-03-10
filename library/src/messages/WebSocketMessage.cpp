/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include "WebSocketMessage.h"

bool WebSocketMessage::hasError() const
{
    return m_error.hasError();
}

WebSocketMessageError WebSocketMessage::getError() const
{
    return m_error;
}

void WebSocketMessage::setError(const WebSocketMessageError &error)
{
    m_error = error;
}
