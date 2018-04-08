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
	virtual int setSocketAddr(struct sockaddr* a_sockaddr, std::string a_ipAdress, uint a_port) = 0;

protected:
	virtual ~IOsSocket(){};

};



#endif /* DEPENDENCYINJECTION_IPV4_IOSSOCKET_H_ */
