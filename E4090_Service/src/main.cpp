//============================================================================
// Name        : transcoderService.cpp
// Author      : JayNgai
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Daemon for MatrixStream Encoder IMX 4090
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "NetworkManager.h"
#include "PublicPort.h"
#include "ManagementPort.h"
#include "EncoderSettingsManager.h"
#include "EncoderSettings.h"
#include "pugixml.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	Network_Manager network_Manager;
	network_Manager = Network_Manager();

	Public_Port public_Port;
	public_Port = Public_Port();
	public_Port.ID = 0;
	public_Port.get_Port_Info();
	//public_Port.set_Port_Info("10.0.1.100", "255.0.0.0", "10.0.1.1", "10.0.1.100");

	network_Manager.add_Public_Port(public_Port);
	network_Manager.print_Public_Port_Info(0);

	Management_Port management_Port;
	management_Port = Management_Port();
	management_Port.ID = 0;
	management_Port.get_Port_Info();

	network_Manager.add_Management_Port(management_Port);
	network_Manager.print_Management_Port_Info(0);

	Encoder_Settings_Manager encoder_Settings_Manager;
	encoder_Settings_Manager = Encoder_Settings_Manager();

	Encoder_Settings encoder_Settings;
	encoder_Settings = Encoder_Settings();
	encoder_Settings.get_Encoder_Settings();

	encoder_Settings_Manager.add_Encoder_Settings(encoder_Settings);
	encoder_Settings_Manager.print_Encoder_Settings(0);

	encoder_Settings_Manager.apply_Encoder_Settings(0);

	return 0;
}
