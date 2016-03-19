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

}

QTEST_APPLESS_MAIN(ProtoBufWebSocketResponseMessageTest)

#include "tst_ProtoBufWebSocketResponseMessageTest.moc"
