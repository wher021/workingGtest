/*
 * ossocket.h
 *
 *  Created on: Mar 24, 2018
 *      Author: willy
 */

#ifndef DEPENDENCYINJECTION_IPV4_OSSOCKET_H_
#define DEPENDENCYINJECTION_IPV4_OSSOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "iossocket.h"

void error(const char *);


class OsSocket : public IOsSocket
{
public:
	OsSocket();
	virtual int socket(IOsSocket::Socket socket_type);

	ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
	               const struct sockaddr *dest_addr, socklen_t addrlen);

	int bind(int sockfd, const struct sockaddr *addr,
	                socklen_t addrlen);
	ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
	                 struct sockaddr *src_addr, socklen_t *addrlen);
	virtual int getSocket();
	virtual int setSocketAddr(std::string a_ipAdress, uint a_port);
	virtual sockaddr* getSocketAddr();

	bool getInit()
	{
		return m_initialized;
	}
	virtual ~OsSocket();
	 friend class SocketTest;
private:
	void setSocket(int a)
	{
		m_socketDescriptor = a;
	}
	bool m_initialized;
	int m_socketDescriptor;
	struct sockaddr* m_ip4addr;
};

#endif /* DEPENDENCYINJECTION_IPV4_OSSOCKET_H_ */
