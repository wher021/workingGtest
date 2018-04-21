/*
 * ossocket.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: willy
 */

#include "../ossocket.h"

#include <cstring>
#include<iostream>

OsSocket::OsSocket() : m_initialized(false), m_socketDescriptor(-1), m_ip4addr(nullptr)
{
}

int OsSocket::socket(IOsSocket::Socket socket_type)
{
	int m_socketDescriptor = -1;
	m_socketDescriptor = ::socket(AF_INET, socket_type == IOsSocket::Socket::SOCK_UDP ? SOCK_DGRAM : SOCK_STREAM, 0);
	if(m_socketDescriptor < 0)
	{
		error("socket error");
	}
	m_initialized = true;
	return m_socketDescriptor;
}

int OsSocket::getSocket()
{
	if(!m_initialized)
	{
		return -1;
	}
	return m_socketDescriptor;
}

int OsSocket::setSocketAddr(std::string a_ipAdress, uint a_port)
{
	sockaddr_in* ip4addr = new sockaddr_in();

	ip4addr->sin_family = AF_INET;
	ip4addr->sin_port = htons(a_port);
	inet_pton(AF_INET, a_ipAdress.c_str(), &ip4addr->sin_addr);
	m_ip4addr = reinterpret_cast<sockaddr*>(ip4addr);
	return 99;
}

sockaddr* OsSocket::getSocketAddr()
{
	return m_ip4addr;
}

ssize_t OsSocket::sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen)
{
	   char buffer[10];

	   std::memset(buffer, 0, sizeof buffer);
	   std::memcpy(buffer, buf, sizeof buffer);

	   int n=::sendto(sockfd, buffer, strlen(buffer),0, dest_addr,addrlen);
	   if(n < 0)
	   {
		   error("sendto error");
	   }
	   return n;
}

int OsSocket::bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{

	  int flag = ::bind(sockfd, addr,addrlen)<0;
	  if(flag < 0)
	       error("binding");
	  return flag;
}

ssize_t OsSocket::recvfrom(int sockfd, void *buf, size_t len, int flags,
        struct sockaddr *src_addr, socklen_t *addrlen)
{
	int expectedLength = 10;
	   int n = ::recvfrom(sockfd,buf,expectedLength,0, src_addr, addrlen);
	   if(n<0)
	   {
		   error("receiving");
	   }
	   return n;
}

OsSocket::~OsSocket() {
	// TODO Auto-generated destructor stub
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}
