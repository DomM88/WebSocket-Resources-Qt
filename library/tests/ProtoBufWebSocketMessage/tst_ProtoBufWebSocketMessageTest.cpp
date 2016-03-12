/**
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 * See LICENSE for more informations.
 *
 */

#include <QString>
#include <QtTest>

#include <SubProtocol.pb.h>
#include <messages/protobuf/ProtoBufWebSocketMessage.h>

class ProtoBufWebSocketMessageTest : public QObject
{
    Q_OBJECT

public:
    ProtoBufWebSocketMessageTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testDefaultMessage();
    void testRequestMessage();
};

ProtoBufWebSocketMessageTest::ProtoBufWebSocketMessageTest()
{
}

void ProtoBufWebSocketMessageTest::initTestCase()
{
}

void ProtoBufWebSocketMessageTest::cleanupTestCase()
{
}

void ProtoBufWebSocketMessageTest::testDefaultMessage()
{
    textsecure::WebSocketMessage *websocketMessage = new textsecure::WebSocketMessage;
    ProtoBufWebSocketMessage protoWebSockMessage(websocketMessage);

    QVERIFY2(protoWebSockMessage.type() == ProtoBufWebSocketMessage::UNKNOWN_MESSAGE,
             "Wrong default type");
    QVERIFY2(protoWebSockMessage.toByteArray().isEmpty(), "Default message not empty");
}

void ProtoBufWebSocketMessageTest::testRequestMessage()
{
}

QTEST_APPLESS_MAIN(ProtoBufWebSocketMessageTest)

#include "tst_ProtoBufWebSocketMessageTest.moc"
