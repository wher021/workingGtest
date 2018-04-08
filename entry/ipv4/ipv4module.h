/*
 * ipv4module.h
 *
 *  Created on: Mar 24, 2018
 *      Author: willy
 */

#ifndef DEPENDENCYINJECTION_IPV4_IPV4MODULE_H_
#define DEPENDENCYINJECTION_IPV4_IPV4MODULE_H_

#include "iossocket.h"
#include "ossocket.h"
#include "osudpconnection.h"

class ipv4module
{
public:
	ipv4module();
	virtual ~ipv4module();
};

#endif /* DEPENDENCYINJECTION_IPV4_IPV4MODULE_H_ */
