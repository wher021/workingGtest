#include "gmock/gmock.h"  // Brings in Google Mock.
#include "../iossocket.h"

class MockSocket : public IOsSocket
{
 public:
	MOCK_METHOD1(socket, int(IOsSocket::Socket socket_type));
	MOCK_METHOD0(getSocket, int());
	MOCK_METHOD2(setSocketAddr, int(std::string a_ipAdress, uint a_port));
	MOCK_METHOD0(getSocketAddr, sockaddr*());
	MOCK_METHOD6(sendto, ssize_t(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen));
	MOCK_METHOD6(recvfrom, ssize_t(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen));
};

