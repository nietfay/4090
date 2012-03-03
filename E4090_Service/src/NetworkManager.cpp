/*
 * NetworkManager.cpp
 *
 *  Created on: 2012-02-13
 *      Author: user
 */

#include "NetworkManager.h"

Network_Manager::Network_Manager()
{
	// TODO Auto-generated constructor stub
}

void Network_Manager::restart_Network()
{
	Utility * util = new Utility();
	util->RunScript((char *) "/etc/init.d/S40network restart");
	delete util;
}

void Network_Manager::update_Network_Ports()
{
	for (public_Ports_Iterator = public_Ports.begin(); public_Ports_Iterator != public_Ports.end(); public_Ports_Iterator++)
	{
		public_Ports_Iterator->get_Port_Info();
	}
	for (management_Ports_Iterator = management_Ports.begin(); management_Ports_Iterator != management_Ports.end(); management_Ports_Iterator++)
	{
		management_Ports_Iterator->get_Port_Info();
	}
}

bool Network_Manager::add_Public_Port(Public_Port Port)
{
	bool result = true;
	public_Ports.push_back(Port);
	return result;
}

bool Network_Manager::remove_Public_Port(int ID)
{
	bool result = true;
	for (public_Ports_Iterator = public_Ports.begin(); public_Ports_Iterator != public_Ports.end(); public_Ports_Iterator++)
	{
		if(public_Ports_Iterator->ID == ID)
		{
			public_Ports.erase(public_Ports_Iterator);
		}
	}
	return result;
}

bool Network_Manager::add_Management_Port(Management_Port Port)
{
	bool result = true;
	management_Ports.push_back(Port);
	return result;
}

bool Network_Manager::remove_Management_Port(int ID)
{
	bool result = true;
	for (management_Ports_Iterator = management_Ports.begin(); management_Ports_Iterator != management_Ports.end(); management_Ports_Iterator++)
	{
		if(management_Ports_Iterator->ID == ID)
		{
			management_Ports.erase(management_Ports_Iterator);
		}
	}
	return result;
}

Public_Port Network_Manager::get_Public_Port(int ID)
{
	Public_Port Port;
	for (public_Ports_Iterator = public_Ports.begin(); public_Ports_Iterator != public_Ports.end(); public_Ports_Iterator++)
	{
		if(public_Ports_Iterator->ID == ID)
		{
			Port = Public_Port(*public_Ports_Iterator);
		}
	}
	return Port;
}

Management_Port Network_Manager::get_Management_Port(int ID)
{
	Management_Port Port;
	for (management_Ports_Iterator = management_Ports.begin(); management_Ports_Iterator != management_Ports.end(); management_Ports_Iterator++)
	{
		if(management_Ports_Iterator->ID == ID)
		{
			Port = Management_Port(*management_Ports_Iterator);
		}
	}
	return Port;
}

void Network_Manager::print_Management_Port_Info(int ID)
{
	for (management_Ports_Iterator = management_Ports.begin(); management_Ports_Iterator != management_Ports.end(); management_Ports_Iterator++)
	{
		if(management_Ports_Iterator->ID == ID)
		{
			cout << "Management Port ID: " << management_Ports_Iterator->ID << endl;
			cout << "Management Port IP: " << management_Ports_Iterator->IP_Address;
			cout << "Management Port Subnet: " << management_Ports_Iterator->Subnet;
			cout << "Management Port Gateway: " << management_Ports_Iterator->Gateway;
			cout << "Management Port DNS 1: " << management_Ports_Iterator->DNS1;
			cout << "Management Port DNS 2: " << management_Ports_Iterator->DNS2;
		}
	}
}

void Network_Manager::print_Public_Port_Info(int ID)
{
	for (public_Ports_Iterator = public_Ports.begin(); public_Ports_Iterator != public_Ports.end(); public_Ports_Iterator++)
	{
		if(public_Ports_Iterator->ID == ID)
		{
			cout << "Public Port ID: " << public_Ports_Iterator->ID << endl;
			cout << "Public Port IP: " << public_Ports_Iterator->IP_Address << endl;
			cout << "Public Port Subnet: " << public_Ports_Iterator->Subnet << endl;
			cout << "Public Port Gateway: " << public_Ports_Iterator->Gateway << endl;
			cout << "Public Port DNS 1: " << public_Ports_Iterator->DNS << endl;
		}
	}
}

Network_Manager::~Network_Manager()
{
	// TODO Auto-generated destructor stub
}
