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
TEST_F(OsUdpConnectionTest, initializeSocketShouldCallSocketAndReturnNegativeIfUnSuccessfull)
{
	//Data
	MockSocket mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup
	EXPECT_CALL(mockSocket, socket(IOsSocket::Socket::SOCK_UDP)).Times(1)
	    .WillOnce(Return(-1));

	//Test
	int res = osUdpConnection.InitializeSocket();

	//Assert
	ASSERT_EQ(-1,res);
}

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

TEST_F(OsUdpConnectionTest, sendToSocketShouldReturnNegativeIfBufferIsNull)
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

TEST_F(OsUdpConnectionTest, sendToSocketShouldReturnNegativeIfPortIsOutOfRange)
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
	int res = osUdpConnection.SendTo("127.0.0.1", 4000, "message");

	//Assert
	ASSERT_EQ(-1,res);
}

TEST_F(OsUdpConnectionTest, sendToSocketShouldSetSocketAndReturn0IfSuccesful)
{
	//Data
	NiceMock<MockSocket>  mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, setSocketAddr(_,_)).Times(1).WillOnce(Return(0));
	//EXPECT_CALL(mockSocket, setSocketAddr(_,_)).Times(1).WillOnce(DoAll(SetArgPointee<0>(*a_sockaddr),
     //       Return(0)));

	//Test
	int res = osUdpConnection.SendTo("127.0.0.1", 4000, "message");

	//Assert
	ASSERT_EQ(0, res);
}

TEST_F(OsUdpConnectionTest, sendToSocketShouldReturnENUM99IfsetSocketFails)
{
	//Data
	MockSocket mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, setSocketAddr(_,_)).Times(1).WillOnce(Return(-1));

	int res = osUdpConnection.SendTo("127.0.0.1", 4000, "message");

	//Assert
	ASSERT_EQ(res, -1);
}

////////////TODO sendToShouldCallSocketGetAdrr!!!!

TEST_F(OsUdpConnectionTest, sendToShouldCallOsSocketSendToAndReturnNegativeIfFail)
{
	//Data
	NiceMock<MockSocket> mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1)
	    .WillOnce(Return(0));
	EXPECT_CALL(mockSocket, sendto(_,_,_,_,_,_)).Times(1)
	    .WillOnce(Return(-1));

	//Test
	int res = osUdpConnection.SendTo("127.0.0.1", 4000, "message");

	//Assert
	ASSERT_EQ(-1,res);
}

//******************************RecvFrom**********************************************//

TEST_F(OsUdpConnectionTest, recvFromShouldGetSocketAndReturnNegativeIfFail)
{
	//Data
	NiceMock<MockSocket> mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);
	char a_buffer[100];
	sockaddr* recvAddr;
	socklen_t* addrLen;

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1).WillOnce(Return(-1));

	//Test
	int res = osUdpConnection.RecvFrom(a_buffer, recvAddr, addrLen);

	//Assert
	ASSERT_EQ(-1,res);
}

TEST_F(OsUdpConnectionTest, recvFromShouldCallRevcFromAndReturnNegativeIfFail)
{
	//Data
	NiceMock<MockSocket> mockSocket;
	OsUdpConnection osUdpConnection(&mockSocket);
	char a_buffer[100];
	sockaddr* recvAddr;
	socklen_t* addrLen;

	//setup
	EXPECT_CALL(mockSocket, getSocket()).Times(1).WillOnce(Return(0));
	EXPECT_CALL(mockSocket, recvfrom(_,_,_,_,_,_)).Times(1).WillOnce(Return(-1));

	//Test
	int res = osUdpConnection.RecvFrom(a_buffer, recvAddr, addrLen);

	//Assert
	ASSERT_EQ(-1,res);
}






