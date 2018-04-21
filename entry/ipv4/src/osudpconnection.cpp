/*
 * osudpconnection.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: willy
 */
#include "../osudpconnection.h"
#include <cstring>

OsUdpConnection::OsUdpConnection(IOsSocket* a_iosSocket)
{
		if(a_iosSocket == nullptr)
		{
			throw std::invalid_argument("awdaw");
		}
		m_iosSocket = a_iosSocket;
}

int OsUdpConnection::InitializeSocket()
{
	int res = m_iosSocket->socket(IOsSocket::Socket::SOCK_UDP);
	if(res < 0)
	{
		return -1;
	}

	return res;
}

int OsUdpConnection::SendTo(std::string a_ipAdress, uint a_port, const char* a_buffer)
{
	int res = -99;

	if(a_ipAdress.empty() || a_buffer == nullptr || a_port <= 1000 || m_iosSocket == nullptr)
	{
		return -1;
	}

	int socketDescriptor = m_iosSocket->getSocket();
	if(socketDescriptor < 0)
	{
		return -1;
	}

	res = m_iosSocket->setSocketAddr(a_ipAdress, a_port);
	if(res < 0)
	{
		//this should be enum & the function should be void!
		int myenum = 99;
		return -1;
	}

	sockaddr* sockAddr = m_iosSocket->getSocketAddr();
	res = m_iosSocket->sendto(socketDescriptor, a_buffer, strlen(a_buffer),0, (const struct sockaddr *)&sockAddr, sizeof(sockAddr));

	return res;
}

int OsUdpConnection::RecvFrom(char *a_buffer, sockaddr* a_recvAddr, socklen_t* a_addrLen)
{
	int res = 99;
	int socketDescriptor = m_iosSocket->getSocket();

	if(socketDescriptor < 0)
	{
		return -1;
	}

	res = m_iosSocket->recvfrom(socketDescriptor, a_buffer, strlen(a_buffer),0, (struct sockaddr *)&a_recvAddr, a_addrLen);
	if(res < 0)
	{
		return -1;
	}
	return 0;
}
