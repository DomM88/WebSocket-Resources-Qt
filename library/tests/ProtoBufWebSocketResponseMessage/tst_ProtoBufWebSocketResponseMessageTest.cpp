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

#include <messages/protobuf/ProtoBufWebSocketResponseMessage.h>

class ProtoBufWebSocketResponseMessageTest : public QObject
{
    Q_OBJECT

public:
    ProtoBufWebSocketResponseMessageTest();

private Q_SLOTS:
    void testConstructor();
};

ProtoBufWebSocketResponseMessageTest::ProtoBufWebSocketResponseMessageTest()
{
}

void ProtoBufWebSocketResponseMessageTest::testConstructor()
{
    google::protobuf::uint64 testId(3745646212);
    google::protobuf::uint32 testStatus(12345);
    std::string testMessage("feuhehefhd");
    std::string testBody("body body body");

    textsecure::WebSocketResponseMessage tsResponseMessage;
    tsResponseMessage.set_status(testStatus);
    tsResponseMessage.set_message(testMessage);
    tsResponseMessage.set_body(testBody);
    tsResponseMessage.set_id(testId);

    ProtoBufWebSocketResponseMessage responseMessage(tsResponseMessage);
    QVERIFY2(responseMessage.status() == testStatus, "Status wasn't set.");
    QVERIFY2(responseMessage.message() == QString::fromStdString(testMessage), "Message wasn't set.");
    QVERIFY2(responseMessage.body() == QString::fromStdString(testBody), "Body wasn't set.");
    QVERIFY2(responseMessage.requestId() == testId, "Test id wasn't set.");
}

QTEST_APPLESS_MAIN(ProtoBufWebSocketResponseMessageTest)

#include "tst_ProtoBufWebSocketResponseMessageTest.moc"
