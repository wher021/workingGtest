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
	int InitializeSocket();
	int SendTo(std::string a_ipAdress, uint a_port, const char* a_buffer);
	int RecvFrom(char *a_buffer, sockaddr* a_recvAddr, socklen_t* a_addrLen);
private:
	IOsSocket* m_iosSocket;
};



#endif /* ENTRY_IPV4_OSUDPCONNECTION_H_ */
