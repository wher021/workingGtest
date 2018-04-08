#include "gmock/gmock.h"  // Brings in Google Mock.
#include "../iossocket.h"

class MockSocket : public IOsSocket
{
 public:
	MOCK_METHOD1(socket, int(IOsSocket::Socket socket_type));
	MOCK_METHOD0(getSocket, int());
	MOCK_METHOD3(setSocketAddr, int(struct sockaddr* a_sockaddr, std::string a_ipAdress, uint a_port));
};
