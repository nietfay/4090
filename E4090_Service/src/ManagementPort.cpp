/*
 * ManagementPort.cpp
 *
 *  Created on: 2012-02-13
 *      Author: user
 */

#include "ManagementPort.h"

Management_Port::Management_Port()
{
	// TODO Auto-generated constructor stub
	ID = 1;
	IP_Address = "";
	Subnet = "";
	Gateway = "";
	DNS1 = "";
	DNS2 = "";
}

Management_Port::Management_Port(const Management_Port& M_P)
{
	ID = M_P.ID;
	IP_Address = M_P.IP_Address;
	Subnet = M_P.Subnet;
	Gateway = M_P.Gateway;
	DNS1 = M_P.DNS1;
	DNS2 = M_P.DNS2;
}

void Management_Port::get_Port_Info()
{
	Utility * util = new Utility();

	/*/usr/share/encoder/NetworkInfo.sh eth0ip*/
	IP_Address = util->RunScript((char*)"/usr/share/encoder/NetworkInfo.sh eth0ip");
	Subnet = util->RunScript((char*)"/usr/share/encoder/NetworkInfo.sh eth0subnet");
	Gateway = util->RunScript((char*)"/usr/share/encoder/NetworkInfo.sh eth0gateway");
	DNS1 = util->RunScript((char*)"/usr/share/encoder/NetworkInfo.sh eth0dns1");
	DNS2 = util->RunScript((char*)"/usr/share/encoder/NetworkInfo.sh eth0dns2");

	delete util;
}

void Management_Port::set_Port_Info(string IP, string Subnet, string Gateway, string DNS1, string DNS2)
{
	string Static_Networketh_Top = "#!/bin/bash\n";
	Static_Networketh_Top += "# Naked variables\n";
	Static_Networketh_Top += "# /settings/networketh0\n";
	Static_Networketh_Top += "\n";
	Static_Networketh_Top += "/bin/echo 'This is the network eth0 settings file.'\n";
	Static_Networketh_Top += "\n";
	Static_Networketh_Top += "# When is a variable 'naked', i.e., lacking the '$' in front?\n";
	Static_Networketh_Top += "# When it is being assigned, rather than referenced.\n";
	Static_Networketh_Top += "\n";
	Static_Networketh_Top += "# Assignment\n";
	Static_Networketh_Top += "\n";
	Static_Networketh_Top += "# Set whether to use ipv4 with 1 to use it and 0 to not use it\n";
	Static_Networketh_Top += "\n";
	Static_Networketh_Top += "useipv4eth0=1\n";
	Static_Networketh_Top += "\n";
	Static_Networketh_Top += "# Set whether to use ipv4 dhcp client with 1 to use it and 0 to not use it. Do not set usestaticv4etho or usemacv4etho to 1 then.\n";
	Static_Networketh_Top += "usedhcpv4eth0=0";
	Static_Networketh_Top += "\n";
	Static_Networketh_Top += "# Set whether to use ipv4 static configuration with 1 to use it and 0 to not use it. Do not set usedhcpv4etho or usemacv4etho to 1 then.\n";
	Static_Networketh_Top += "usestaticv4eth0=1\n";

	string Static_Networketh_IP = "addressv4eth0=";
	Static_Networketh_IP += IP + "\n";

	string Static_Networketh_Subnet = "subnetv4eth0=";
	Static_Networketh_Subnet += Subnet + "\n";

	string Static_Networketh_Gateway = "gatewayv4eth0=";
	Static_Networketh_Gateway += Gateway + "\n";

	string Static_Networketh_DNS1 = "dns1v4eth0=";
	Static_Networketh_DNS1 += DNS1 + "\n";

	string Static_Networketh_DNS2 = "dns2v4eth0=";
	Static_Networketh_DNS2 += DNS2 + "\n";

	string Static_Networketh_Bottom = "# Set whether to use ipv4 configuration based on the last 2 characters in the mac address in the subnet 255.255.255.0 with 1 to use it and 0 to not use it. Do not set usedhcpv4etho or usestaticv4etho to 1 then.\n";
	Static_Networketh_Bottom += "usemacv4eth0=0\n";
	Static_Networketh_Bottom += "addressmacv4eth0=10.0.0\n";
	Static_Networketh_Bottom += "gatewaymacv4eth0=10.0.0.254\n";
	Static_Networketh_Bottom += "\n";
	Static_Networketh_Bottom += "# Set whether to use ipv6 with 1 to use it and 0 to not use it\n";
	Static_Networketh_Bottom += "useipv6eth0=1\n";
	Static_Networketh_Bottom += "\n";
	Static_Networketh_Bottom += "# Set whether to use ipv6 dhcp client with 1 to use it and 0 to not use it. Do not set usestaticv6etho or usemacv6etho to 1 then.";
	Static_Networketh_Bottom += "\n";
	Static_Networketh_Bottom += "usedhcpv6eth0=0\n";
	Static_Networketh_Bottom += "\n";
	Static_Networketh_Bottom += "# Set whether to use ipv6 static configuration with 1 to use it and 0 to not use it. Do not set usedhcpv6etho or usemacv6etho to 1 then.";
	Static_Networketh_Bottom += "usestaticv6eth0=0\n";
	Static_Networketh_Bottom += "addressv6eth0=2001:0000:0000:0000:0000:0000:0000:0001\n";
	Static_Networketh_Bottom += "\n";
	Static_Networketh_Bottom += "subnetv6eth0=64\n";
	Static_Networketh_Bottom += "gatewayv6eth0=2001:0000:0000:0000:0000:0000:0000:FFFE\n";
	Static_Networketh_Bottom += "dns1v6eth0=2001:0000:0000:0000:0000:0000:0000:0002\n";
	Static_Networketh_Bottom += "dns2v6eth0=2001:0000:0000:0000:0000:0000:0000:0003\n";
	Static_Networketh_Bottom += "\n";
	Static_Networketh_Bottom += "# Set whether to use ipv6 configuration based on the mac address in the subnet /64 with 1 to use it and 0 to not use it. Do not set usedhcpv6etho or usestaticv6etho to 1 then.\n";
	Static_Networketh_Bottom += "usemacv6eth0=1\n";
	Static_Networketh_Bottom += "addressmacv6eth0=2001:0000:0000:0000\n";
	Static_Networketh_Bottom += "gatewaymacv6eth0=2001:0000:0000:0000:0000:0000:0000:FFFE";

	Utility * util = new Utility();

	string FileStr = Static_Networketh_Top + Static_Networketh_IP + Static_Networketh_Subnet + Static_Networketh_Gateway + Static_Networketh_DNS1 + Static_Networketh_DNS2 + Static_Networketh_Bottom;

	util->WriteToFile((char*)"/settings/networketh0", FileStr.c_str());

	util->RunScript((char *) "/bin/chmod -R 777 /settings/networketh0");
	util->RunScript((char *) "/usr/bin/dos2unix -u /settings/networketh0");

	delete util;
}

void Management_Port::set_Port_Info()
{
	string DHCP_Networketh = "#!/bin/bash\n";
	DHCP_Networketh += "# Naked variables\n";
	DHCP_Networketh += "# /settings/networketh0\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "/bin/echo 'This is the network eth0 settings file.'\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# When is a variable 'naked', i.e., lacking the '$' in front?\n";
	DHCP_Networketh += "# When it is being assigned, rather than referenced.\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Assignment\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv4 with 1 to use it and 0 to not use it\n";
	DHCP_Networketh += "useipv4eth0=1\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv4 dhcp client with 1 to use it and 0 to not use it. Do not set usestaticv4etho or usemacv4etho to 1 then.\n";
	DHCP_Networketh += "usedhcpv4eth0=1\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv4 static configuration with 1 to use it and 0 to not use it. Do not set usedhcpv4etho or usemacv4etho to 1 then.\n";
	DHCP_Networketh += "usestaticv4eth0=0\n";
	DHCP_Networketh += "addressv4eth0=127.0.0.1\n";
	DHCP_Networketh += "subnetv4eth0=127.0.0.1\n";
	DHCP_Networketh += "gatewayv4eth0=127.0.0.1\n";
	DHCP_Networketh += "dns1v4eth0=127.0.0.1\n";
	DHCP_Networketh += "dns2v4eth0=127.0.0.1\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv4 configuration based on the last 2 characters in the mac address in the subnet 255.255.255.0 with 1 to use it and 0 to not use it. Do not set usedhcpv4etho or usestaticv4etho to 1 then.\n";
	DHCP_Networketh += "usemacv4eth0=0\n";
	DHCP_Networketh += "addressmacv4eth0=10.0.0\n";
	DHCP_Networketh += "gatewaymacv4eth0=10.0.0.254\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv6 with 1 to use it and 0 to not use it\n";
	DHCP_Networketh += "useipv6eth0=1\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv6 dhcp client with 1 to use it and 0 to not use it. Do not set usestaticv6etho or usemacv6etho to 1 then.\n";
	DHCP_Networketh += "usedhcpv6eth0=0\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv6 static configuration with 1 to use it and 0 to not use it. Do not set usedhcpv6etho or usemacv6etho to 1 then.\n";
	DHCP_Networketh += "usestaticv6eth0=0\n";
	DHCP_Networketh += "addressv6eth0=2001:0000:0000:0000:0000:0000:0000:0001\n";
	DHCP_Networketh += "subnetv6eth0=64\n";
	DHCP_Networketh += "gatewayv6eth0=2001:0000:0000:0000:0000:0000:0000:FFFE\n";
	DHCP_Networketh += "dns1v6eth0=2001:0000:0000:0000:0000:0000:0000:0002\n";
	DHCP_Networketh += "dns2v6eth0=2001:0000:0000:0000:0000:0000:0000:0003\n";
	DHCP_Networketh += "\n";
	DHCP_Networketh += "# Set whether to use ipv6 configuration based on the mac address in the subnet /64 with 1 to use it and 0 to not use it. Do not set usedhcpv6etho or usestaticv6etho to 1 then.\n";
	DHCP_Networketh += "usemacv6eth0=1\n";
	DHCP_Networketh += "addressmacv6eth0=2001:0000:0000:0000\n";
	DHCP_Networketh += "gatewaymacv6eth0=2001:0000:0000:0000:0000:0000:0000:FFFE\n";
	DHCP_Networketh += "\n";

	Utility * util = new Utility();

	util->WriteToFile((char*)"/settings/networketh0", DHCP_Networketh.c_str());

	util->RunScript((char *) "/bin/chmod -R 777 /settings/networketh0");
	util->RunScript((char *) "/usr/bin/dos2unix -u /settings/networketh0");

	delete util;
}

string Management_Port::get_IP()
{
	return IP_Address;
}

string Management_Port::get_Subnet()
{
	return Subnet;
}

string Management_Port::get_Gateway()
{
	return Gateway;
}

string Management_Port::get_DNS1()
{
	return DNS1;
}

string Management_Port::get_DNS2()
{
	return DNS2;
}

Management_Port::~Management_Port()
{
	// TODO Auto-generated destructor stub
}

