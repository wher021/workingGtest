/*
 * iossocket.h
 *
 *  Created on: Mar 24, 2018
 *      Author: willy
 */

#ifndef DEPENDENCYINJECTION_IPV4_IOSSOCKET_H_
#define DEPENDENCYINJECTION_IPV4_IOSSOCKET_H_

#include <sys/socket.h>
#include <iostream>

class IOsSocket
{
public:
	enum class Socket
	{
		SOCK_TCP,
		SOCK_UDP
	};
	virtual int socket(IOsSocket::Socket socket_type) = 0;
	virtual int getSocket() = 0;
	virtual int setSocketAddr(std::string a_ipAdress, uint a_port) = 0;
	virtual sockaddr* getSocketAddr() = 0;
	virtual ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
	               const struct sockaddr *dest_addr, socklen_t addrlen) = 0;
	virtual ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
	                 struct sockaddr *src_addr, socklen_t *addrlen) = 0;

protected:
	virtual ~IOsSocket(){};

};



#endif /* DEPENDENCYINJECTION_IPV4_IOSSOCKET_H_ */
