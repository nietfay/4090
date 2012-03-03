/*
 * PublicPort.cpp
 *
 * Created on: 2012-02-13
 * Author: JayNgai
 */

#include "PublicPort.h"
#include <stdio.h>
#include <string.h>

Public_Port::Public_Port()
{
	// TODO Auto-generated constructor stub
	ID = 0;
	IP_Address = "192.168.1.200";
	Subnet = "255.255.255.0";
	Gateway = "192.168.1.1";
	DNS = "192.168.1.1";

}

Public_Port::Public_Port(const Public_Port& P_P)
{
	ID = P_P.ID;
	IP_Address = P_P.IP_Address;
	Subnet = P_P.Subnet;
	Gateway = P_P.Gateway;
	DNS = P_P.DNS;
}

bool Public_Port::get_Port_Info()
{
	pugi::xml_document doc;
	pugi::xml_parse_result xmlResult = doc.load_file("/settings/Encoder.xml");
	pugi::xml_node Root;
	if (!xmlResult)
	{
		xmlResult = doc.load_file("/applications/DefaultEncoder.xml");
		if (!xmlResult)
		{
			return false;
		}
		else
		{
			Root = doc.first_child();
		}
	}
	else
	{
		Root = doc.first_child();
	}

	pugi::xml_node System = Root.child("System");

	pugi::xml_node IPAddress = System.child("IPAddress");
	this->IP_Address = (string)IPAddress.first_child().value();

	pugi::xml_node Gateway = System.child("DefaultGateway");
	this->Gateway = (string)Gateway.first_child().value();

	pugi::xml_node Subnet = System.child("SubnetMask");
	this->Subnet = (string)Subnet.first_child().value();

	pugi::xml_node DNS = System.child("DNS");
	this->DNS = (string)DNS.first_child().value();

	return true;
}

void Public_Port::set_Port_Info(string IP, string Subnet, string Gateway, string DNS)
{
	this->IP_Address = IP;
	this->Subnet = Subnet;
	this->Gateway = Gateway;
	this->DNS = DNS;

	string Public_Port_Top = "CNL\n";
	Public_Port_Top += ">> command 3\n";
	Public_Port_Top += "RTP\n";
	Public_Port_Top += ">> OperationMode 2\n";
	Public_Port_Top += "CNL\n";
	Public_Port_Top += ">> command 6\n";
	Public_Port_Top += "TCP\n";

	string Public_Port_Middle = "";
	if(DNS != "")
	{
		Public_Port_Middle = ">> SetMode 2 IPaddress " + IP + " NetMask " + Subnet + " GateWay " + Gateway + " dns " + DNS + "\n";
	}
	else
	{
		Public_Port_Middle = ">> SetMode 2 IPaddress " + IP + " NetMask " + Subnet + "\n";
	}

	string Public_Port_Bottom = "RTP\n";
	Public_Port_Bottom += ">> OperationMode 1\n";
	Public_Port_Bottom += "CNL\n";
	Public_Port_Bottom += ">> command 5\n";
	Public_Port_Bottom += "CNL\n";
	Public_Port_Bottom += ">> command 2\n";

	Utility * util = new Utility();

	string FileStr = Public_Port_Top + Public_Port_Middle + Public_Port_Bottom;

	util->WriteToFile((char*)"/settings/PublicApply", FileStr.c_str());

	util->RunScript((char *) "/bin/chmod -R 777 /settings/PublicApply");
	util->RunScript((char *) "/usr/bin/dos2unix -u /settings/PublicApply");

	delete util;
}

string Public_Port::get_IP()
{
	return IP_Address;
}

string Public_Port::get_Subnet()
{
	return Subnet;
}

string Public_Port::get_Gateway()
{
	return Gateway;
}

string Public_Port::get_DNS()
{
	return DNS;
}

Public_Port::~Public_Port()
{
	// TODO Auto-generated destructor stub
}

