/*
 * osudpconnection.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: willy
 */
#include "../osudpconnection.h"

OsUdpConnection::OsUdpConnection(IOsSocket* a_iosSocket) : m_sockaddr(nullptr)
{
		if(a_iosSocket == nullptr)
		{
			throw std::invalid_argument("awdaw");
		}
		m_iosSocket = a_iosSocket;
}

int OsUdpConnection::SendTo(std::string a_ipAdress, uint a_port, const char* a_buffer)
{
	if(a_ipAdress.empty() || a_buffer == nullptr || a_port <= 1000 || m_iosSocket == nullptr)
	{
		return -1;
	}
	int res = m_iosSocket->getSocket();
	if(res < 0)
	{
		return -1;
	}
	res = m_iosSocket->socket(IOsSocket::Socket::SOCK_UDP);
	if(res < 0)
	{
		return -1;
	}
	res = m_iosSocket->setSocketAddr(m_sockaddr, a_ipAdress, a_port);
	if(m_sockaddr == nullptr)
	{
		res = 99;
	}

	return res;
}
