/*
 * PublicPort.h
 *
 *  Created on: 2012-02-13
 *      Author: JayNgai
 */
#include <stdio.h>
#include <string>
#include "Utility.h"
#include "pugixml.hpp"
using namespace std;

#ifndef PUBLICPORT_H_
#define PUBLICPORT_H_

class Public_Port
{
	public:
		//Functions
		Public_Port();
		//Copy Constructor
		Public_Port(const Public_Port& P_P);
		//Gather Ethernet Port Information
		bool get_Port_Info();
		//Set Ethernet Port Information
		void set_Port_Info(string IP, string Subnet, string Gateway, string DNS);
		//Return the IP Address after get_Port_Info is called
		string get_IP();
		//Return the Subnet Address after get_Port_Info is called
		string get_Subnet();
		//Return the Gateway Address after get_Port_Info is called
		string get_Gateway();
		//Return the DNS Address after get_Port_Info is called
		string get_DNS();

		virtual ~Public_Port();

		//Variables
		int ID;
		string IP_Address;
		string Subnet;
		string Gateway;
		string DNS;
};

#endif /* PUBLICPORT_H_ */
