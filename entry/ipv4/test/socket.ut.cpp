#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../iossocket.h"
#include "../ossocket.h"

class SocketTest : public testing::Test
{
public:
	SocketTest()
	{
	}
	static void initSocket(OsSocket& a_osSocket)
	{
		a_osSocket.socket(IOsSocket::Socket::SOCK_UDP);
		a_osSocket.setSocket(3);
	}
protected:

 virtual void SetUp() {
 }

 virtual void TearDown() {
 }
};


TEST_F(SocketTest, socketShouldReturn0IfFail) {
  //Data
	OsSocket osSocket;

	//Setup

	//Test
	int res = osSocket.socket(IOsSocket::Socket::SOCK_UDP);

	//Analysis
  ASSERT_GT(res, -1);
}

TEST_F(SocketTest, socketShouldSetInitializedToTrue) {
  //Data
	OsSocket osSocket;

	//Setup

	//Test
	osSocket.socket(IOsSocket::Socket::SOCK_UDP);

	//Analysis
  ASSERT_TRUE(osSocket.getInit());
}

TEST_F(SocketTest, getSocketShouldReturnNegativeIfNotInitialized) {
  //Data
	OsSocket osSocket;

	//Setup

	//Test & Analysis
  ASSERT_EQ(-1, osSocket.getSocket());
}

TEST_F(SocketTest, getSocketShouldReturnSocketIfInitialized) {
	//Data
	OsSocket osSocket;

	//Setup
	SocketTest::initSocket(osSocket);

	//Test & Analysis
  ASSERT_GT(osSocket.getSocket(), -1);
}

