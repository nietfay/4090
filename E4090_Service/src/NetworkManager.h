/*
 * NetworkManager.h
 *
 *  Created on: 2012-02-13
 *      Author: user
 */
#include "ManagementPort.h"
#include "PublicPort.h"
#include "Utility.h"
#include <list>

#ifndef NETWORKMANAGER_H_
#define NETWORKMANAGER_H_

class Network_Manager {
public:
	Network_Manager();

	//Restart the Network Service
	void restart_Network();
	//Calling all Ethernet Ports under this manager to gather the latest Info
	void update_Network_Ports();
	//Add a public port into this manager
	bool add_Public_Port(Public_Port Port);
	//Remove a public port from this manager
	bool remove_Public_Port(int ID);
	//Add a Management Port into this manager
	bool add_Management_Port(Management_Port Port);
	//Remove a management port from this manager
	bool remove_Management_Port(int ID);
	//return a Public Port object by the ID
	Public_Port get_Public_Port(int ID);
	//return a Management Port object by the ID
	Management_Port get_Management_Port(int ID);

	/* DEBUG FUNCTIONS */
	void print_Management_Port_Info(int ID);
	void print_Public_Port_Info(int ID);

	virtual ~Network_Manager();

	//Variables
	list<Public_Port> public_Ports;
	list<Public_Port>::iterator public_Ports_Iterator;

	list<Management_Port> management_Ports;
	list<Management_Port>::iterator management_Ports_Iterator;

	int Error;
};

#endif /* NETWORKMANAGER_H_ */
