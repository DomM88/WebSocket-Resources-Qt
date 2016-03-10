/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include "WebSocketMessageError.h"

WebSocketMessageError::WebSocketMessageError()
    : m_error(Error::NoError)
{
}

WebSocketMessageError::WebSocketMessageError(WebSocketMessageError::Error error,
                                             const QString &text)
    : m_error(error)
    , m_text(text)
{
}

bool WebSocketMessageError::hasError() const
{
    return (m_error != Error::NoError);
}

WebSocketMessageError::Error WebSocketMessageError::error() const
{
    return m_error;
}

void WebSocketMessageError::setError(const Error &error)
{
    m_error = error;
}

QString WebSocketMessageError::text() const
{
    return m_text;
}

void WebSocketMessageError::setText(const QString &text)
{
    m_text = text;
}


