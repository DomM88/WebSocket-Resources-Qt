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
    void testResponseMessage();
    void testFromEmptyBuffer();
    void testRequestFromBuffer();
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
    std::string testVerb("hfhfhfh");
    std::string testPath("feuhehefhd");
    std::string testBody("body body body");
    google::protobuf::uint64 testId(3745646212);

    textsecure::WebSocketRequestMessage *tsRequestMessage = new textsecure::WebSocketRequestMessage;
    tsRequestMessage->set_verb(testVerb);
    tsRequestMessage->set_path(testPath);
    tsRequestMessage->set_id(testId);
    tsRequestMessage->set_body(testBody);

    textsecure::WebSocketMessage *tsMessage = new textsecure::WebSocketMessage;
    tsMessage->set_type(textsecure::WebSocketMessage_Type_REQUEST);
    tsMessage->set_allocated_request(tsRequestMessage);
    ProtoBufWebSocketMessage protoWebSockMessage(tsMessage);
    QSharedPointer<WebSocketRequestMessage> requestMessage = protoWebSockMessage.requestMessage();

    QVERIFY2(requestMessage->verb() == QString::fromStdString(testVerb), "Verb wasn't set.");
    QVERIFY2(requestMessage->path() == QString::fromStdString(testPath), "Path wasn't set.");
    QVERIFY2(requestMessage->body() == QString::fromStdString(testBody), "Body wasn't set.");
    QVERIFY2(requestMessage->requestId() == testId, "Test id wasn't set.");
}

void ProtoBufWebSocketMessageTest::testResponseMessage()
{
    google::protobuf::uint64 testId(3745646212);
    google::protobuf::uint32 testStatus(12345);
    std::string testMessage("feuhehefhd");
    std::string testBody("body body body");

    textsecure::WebSocketResponseMessage *tsResponseMessage = new textsecure::WebSocketResponseMessage;
    tsResponseMessage->set_id(testId);
    tsResponseMessage->set_status(testStatus);
    tsResponseMessage->set_message(testMessage);
    tsResponseMessage->set_body(testBody);

    textsecure::WebSocketMessage *tsMessage = new textsecure::WebSocketMessage;
    tsMessage->set_type(textsecure::WebSocketMessage_Type_RESPONSE);
    tsMessage->set_allocated_response(tsResponseMessage);

    ProtoBufWebSocketMessage protoWebSockMessage(tsMessage);
    QSharedPointer<WebSocketResponseMessage> responseMessage = protoWebSockMessage.responseMessage();

    QVERIFY2(responseMessage->status() == testStatus, "Status wasn't set.");
    QVERIFY2(responseMessage->message() == QString::fromStdString(testMessage), "Message wasn't set.");
    QVERIFY2(responseMessage->body() == QString::fromStdString(testBody), "Body wasn't set.");
    QVERIFY2(responseMessage->requestId() == testId, "Test id wasn't set.");
}

void ProtoBufWebSocketMessageTest::testFromEmptyBuffer()
{
    QByteArray emptyArray;
    ProtoBufWebSocketMessage webSocketMessage(emptyArray);

    QVERIFY2(webSocketMessage.type() == ProtoBufWebSocketMessage::UNKNOWN_MESSAGE, "Wrong default type");
    QVERIFY2(webSocketMessage.toByteArray().isEmpty(), "Default message not empty");
}

void ProtoBufWebSocketMessageTest::testRequestFromBuffer()
{
    std::string testVerb("hfhfhfh");
    std::string testPath("feuhehefhd");
    std::string testBody("body body body");
    google::protobuf::uint64 testId(3745646212);

    textsecure::WebSocketRequestMessage *tsRequestMessage = new textsecure::WebSocketRequestMessage;
    tsRequestMessage->set_verb(testVerb);
    tsRequestMessage->set_path(testPath);
    tsRequestMessage->set_body(testBody);
    tsRequestMessage->set_id(testId);

    textsecure::WebSocketMessage *tsMessage = new textsecure::WebSocketMessage;
    tsMessage->set_type(textsecure::WebSocketMessage_Type_REQUEST);
    tsMessage->set_allocated_request(tsRequestMessage);

    ProtoBufWebSocketMessage message(QByteArray::fromStdString(tsMessage->SerializeAsString()));
    QVERIFY2(message.type() == ProtoBufWebSocketMessage::REQUEST_MESSAGE, "Wrong message type");

    auto requestMessage = message.requestMessage();
    QVERIFY2(requestMessage->verb() == QString::fromStdString(testVerb), "Verb wasn't set.");
    QVERIFY2(requestMessage->path() == QString::fromStdString(testPath), "Path wasn't set.");
    QVERIFY2(requestMessage->body() == QString::fromStdString(testBody), "Body wasn't set.");
    QVERIFY2(requestMessage->requestId() == testId, "Test id wasn't set.");
}

QTEST_APPLESS_MAIN(ProtoBufWebSocketMessageTest)

#include "tst_ProtoBufWebSocketMessageTest.moc"
