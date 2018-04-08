/*
 * osudpconnection.ut.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: willy
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mocksocket.h"
#include <iostream>
#include "../osudpconnection.h"
using ::testing::_;
using ::testing::Return;
using ::testing::NiceMock;
using testing::ReturnPointee;
using ::testing::SetArgPointee;

class OsUdpConnectionTest : public testing::Test
{
protected:
	static void init(sockaddr* a_sockaddr, OsUdpConnection& a_udpConnection)
	{
		a_udpConnection.setSocketAddr(a_sockaddr);
	}
 // Remember that SetUp() is run immediately before a test starts.
 // This is a good place to record the start time.
 virtual void SetUp() {
 }

 // TearDown() is invoked immediately after a test finishes.  Here we
 // check if the test was too slow.
 virtual void TearDown() {
 }
};

TEST_F(OsUdpConnectionTest, constructorShouldThrowNullExceptionIfIOsSocketNull)
{
	//data

	//setup

	//Test && Assert
	ASSERT_THROW
	({
		OsUdpConnection* ms = new OsUdpConnection(nullptr);
	},std::invalid_argument);
}

//TODO This test is required if there are no constructor tests for memberVariables
//TEST_F(OsUdpConnectionTest, sendToShouldReturnNegativeIfOsSocketIsNULL)
//{
//	//Data
//	OsUdpConnection osUdpConnection(nullptr);
//
//	//Setup
//
//	//Test
//	int res = osUdpConnection.SendTo("127.0.0.1",4000, "message");
//
//	//Assert
//	ASSERT_EQ(-1, res);
//}

TEST_F(OsUdpConnectionTest, sendToShouldReturnNegativeIfAdressIsEmpty)
{
	//Data
	NiceMock<MockSocket> mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup

	//Test
	int res = osUdpConnection.SendTo(std::string(), 4000,"message");

	//Assert
	ASSERT_EQ(-1, res);
}

TEST_F(OsUdpConnectionTest, sendToShouldReturnNegativeIfBufferIsNull)
{
	//Data
	NiceMock<MockSocket> mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup

	//Test
	int res = osUdpConnection.SendTo("127.0.0.1",4000,nullptr);

	//Assert
	ASSERT_EQ(-1, res);
}

TEST_F(OsUdpConnectionTest, sendToShouldReturnNegativeIfPortIsOutOfRange)
{
	//Data
	NiceMock<MockSocket> mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup

	//Test
	int res = osUdpConnection.SendTo("127.0.0.1",12, "message");

	//Assert
	ASSERT_EQ(-1, res);
}

TEST_F(OsUdpConnectionTest, sendToShouldCallGetSocketAndReturnNegativeIfUnSuccessfull)
{
	//Data
	NiceMock<MockSocket> mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1)
	    .WillOnce(Return(-1));

	//Test
	int res = osUdpConnection.SendTo("127.0.0.1", 4000,"message");

	//Assert
	ASSERT_EQ(-1,res);
}

TEST_F(OsUdpConnectionTest, sendToShouldCallSocketAndReturnNegativeIfUnSuccessfull)
{
	//Data
	MockSocket mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, socket(IOsSocket::Socket::SOCK_UDP)).Times(1)
	    .WillOnce(Return(-1));

	//Test
	int res = osUdpConnection.SendTo("127.0.0.1",4000, "message");

	//Assert
	ASSERT_EQ(-1,res);
}


TEST_F(OsUdpConnectionTest, sendToShouldSetENUMIfSuccesful)
{
	//Data
	MockSocket mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	sockaddr* a_sockaddr = new sockaddr();
	OsUdpConnectionTest::init(a_sockaddr, osUdpConnection);

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, socket(IOsSocket::Socket::SOCK_UDP)).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, setSocketAddr(_,_,_)).Times(1).WillOnce(DoAll(SetArgPointee<0>(*a_sockaddr),
            Return(0)));

	//Test
	int res = osUdpConnection.SendTo("127.0.0.1", 4000, "message");

	//Assert
	ASSERT_EQ(0, res);
}

TEST_F(OsUdpConnectionTest, sendToShouldReturnENUM99IfsetSocketAddrIsNull)
{
	//Data
	MockSocket mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, socket(IOsSocket::Socket::SOCK_UDP)).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, setSocketAddr(_,_,_)).Times(1).WillOnce(Return(-1));

	int res = osUdpConnection.SendTo("127.0.0.1", 4000, "message");

	//Assert
	ASSERT_EQ(res, 99);
}



