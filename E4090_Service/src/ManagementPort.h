/*
 * ManagementPort.h
 *
 *  Created on: 2012-02-13
 *      Author: user
 */
#include <string>
#include <stdio.h>
#include "Utility.h"
using namespace std;

#ifndef MANAGEMENTPORT_H_
#define MANAGEMENTPORT_H_

class Management_Port
{
	public:
		Management_Port();
		//Copy Constructor
		Management_Port(const Management_Port& M_P);
		//Gather Ethernet Port Information
		void get_Port_Info();
		//Set Ethernet Port Information to Static
		void set_Port_Info(string IP, string Subnet, string Gateway, string DNS1, string DNS2);
		//Set Ethernet Port Information to DHCP
		void set_Port_Info();
		//Return the IP Address after get_Port_Info is called
		string get_IP();
		//Return the Subnet Address after get_Port_Info is called
		string get_Subnet();
		//Return the Gateway Address after get_Port_Info is called
		string get_Gateway();
		//Return the DNS 1 Address after get_Port_Info is called
		string get_DNS1();
		//Return the DNS 2 Address after get_Port_Info is called
		string get_DNS2();

		virtual ~Management_Port();

		//Variables
		int ID;
		string IP_Address;
		string Subnet;
		string Gateway;
		string DNS1;
		string DNS2;

};

#endif /* MANAGEMENTPORT_H_ */
