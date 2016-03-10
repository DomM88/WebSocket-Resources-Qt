/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>

#ifndef WEBSOCKETMESSAGEERROR_H
#define WEBSOCKETMESSAGEERROR_H

class WebSocketMessageError
{
public:
    enum class Error {
        NoError,
        Parse,
        WrongAttributes
    };

    explicit WebSocketMessageError();
    WebSocketMessageError(Error error, const QString &text);

    bool hasError() const;
    Error error() const;
    void setError(const Error &error);

    QString text() const;
    void setText(const QString &text);

private:
    Error m_error;
    QString m_text;
};

#endif // WEBSOCKETMESSAGEERROR_H
