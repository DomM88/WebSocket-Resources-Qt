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

#include <messages/protobuf/ProtoBufWebSocketRequestMessage.h>

class ProtoBufWebSocketRequestMessageTest : public QObject
{
    Q_OBJECT

public:
    ProtoBufWebSocketRequestMessageTest();

private Q_SLOTS:
    void testConstructor();
};

ProtoBufWebSocketRequestMessageTest::ProtoBufWebSocketRequestMessageTest()
{
}

void ProtoBufWebSocketRequestMessageTest::testConstructor()
{
    std::string testVerb("hfhfhfh");
    std::string testPath("feuhehefhd");
    std::string testBody("body body body");
    google::protobuf::uint64 testId(3745646212);

    textsecure::WebSocketRequestMessage tsRequestMessage;
    tsRequestMessage.set_verb(testVerb);
    tsRequestMessage.set_path(testPath);
    tsRequestMessage.set_body(testBody);
    tsRequestMessage.set_id(testId);

    ProtoBufWebSocketRequestMessage requestMessage(tsRequestMessage);
    QVERIFY2(requestMessage.verb() == QString::fromStdString(testVerb), "Verb wasn't set.");
    QVERIFY2(requestMessage.path() == QString::fromStdString(testPath), "Path wasn't set.");
    QVERIFY2(requestMessage.body() == QString::fromStdString(testBody), "Body wasn't set.");
    QVERIFY2(requestMessage.requestId() == testId, "Test id wasn't set.");
}

QTEST_APPLESS_MAIN(ProtoBufWebSocketRequestMessageTest)

#include "tst_ProtoBufWebSocketRequestMessageTest.moc"
