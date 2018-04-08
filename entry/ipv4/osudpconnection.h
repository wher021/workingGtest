/*
 * osudpconnection.h
 *
 *  Created on: Apr 7, 2018
 *      Author: willy
 */

#ifndef ENTRY_IPV4_OSUDPCONNECTION_H_
#define ENTRY_IPV4_OSUDPCONNECTION_H_
#include "iossocket.h"
#include <stdexcept>

class OsUdpConnection
{
public:
	OsUdpConnection(IOsSocket* a_iosSocket);
	int SendTo(std::string a_ipAdress, uint a_port, const char* a_buffer);
	friend class OsUdpConnectionTest;
private:
	void setSocketAddr(struct sockaddr* a)
	{
		m_sockaddr = a;
	}
	IOsSocket* m_iosSocket;
	struct sockaddr* m_sockaddr;
};



#endif /* ENTRY_IPV4_OSUDPCONNECTION_H_ */
