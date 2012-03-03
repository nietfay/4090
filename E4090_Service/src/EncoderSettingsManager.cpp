/*
 * EncoderSettingsManager.cpp
 *
 *  Created on: 2012-02-17
 *      Author: user
 */

#include "EncoderSettingsManager.h"

Encoder_Settings_Manager::Encoder_Settings_Manager()
{
	// TODO Auto-generated constructor stub
	this->Default_Encoder_Settings = Encoder_Settings();
	this->Default_Encoder_Settings.ID = -1;
}

bool Encoder_Settings_Manager::add_Encoder_Settings(Encoder_Settings encoder_Settings)
{
	bool result = true;
	Encoder_Settings_List.push_back(encoder_Settings);
	return result;
}

bool Encoder_Settings_Manager::remove_Encoder_Settings(int ID)
{
	bool result = true;
	for (Encoder_Settings_Iterator = Encoder_Settings_List.begin(); Encoder_Settings_Iterator != Encoder_Settings_List.end(); Encoder_Settings_Iterator++)
	{
		if(Encoder_Settings_Iterator->ID == ID)
		{
			Encoder_Settings_List.erase(Encoder_Settings_Iterator);
		}
	}
	return result;
}

bool Encoder_Settings_Manager::apply_Encoder_Settings(int ID)
{
	bool result = false;
	Encoder_Settings encoder_Settings = this->get_Encoder_Settings(ID);
	Utility util = Utility();

	//Create the apply script
	string applyStr;

	applyStr = "CNL\n";
	applyStr += ">> command 3\n";

	applyStr += "RTP\n";
	applyStr += ">> OperationMode 2\n";

	applyStr += "CNL\n";
	applyStr += ">> command 6\n";

	applyStr += "AVS\n";
	applyStr += ">> AudioSourceInput " + encoder_Settings.Audio_Source;
	applyStr += " VideoSourceInput " + encoder_Settings.Video_Source;
	applyStr += " \n";

	applyStr += "VEN\n";
	applyStr += ">> PID " + encoder_Settings.Video_PID;
	applyStr += " EncoderType " + encoder_Settings.Audio_Type;
	applyStr += " VideoBitRate " + encoder_Settings.Video_Bitrate;
	applyStr += " CodingMode " + encoder_Settings.Encoding_Mode;
	applyStr += " RateControlMode " + encoder_Settings.Matrix_Cast_Video_Engine;
	applyStr += " VBRMinimumBitrate ";
	applyStr += " VBRMaximumBitrate ";
	applyStr += " HorizontalRescaledResolution " + encoder_Settings.Horizontal_Rescaled_Resolution;
	applyStr += " GOPSize " + encoder_Settings.GOP_Size;
	applyStr += " SceneChangeDetectionEnable " + encoder_Settings.Fast_Channel_Changing;
	applyStr += " IDRfrequency " + encoder_Settings.IDR_Frequency;
	applyStr += " AspectRatio " + encoder_Settings.Aspect_Ratio;
	applyStr += " inversetelecinedetectionenable " + encoder_Settings.Inverse_Telecine;
	applyStr += " \n";

	applyStr += "264\n";
	applyStr += ">> LoopFilterMode " + encoder_Settings.Loop_Filter;
	applyStr += " LoopFilterAlphaC0Offset " + encoder_Settings.Loop_Filter_Alpha;
	applyStr += " LoopFilterBetaOffset " + encoder_Settings.Loop_Filter_Beta;
	applyStr += " \n";

	applyStr += "AEN\n";
	applyStr += ">> PID " + encoder_Settings.Audio_PID;
	applyStr += " EncoderType " + encoder_Settings.Audio_Type;
	//appluStr += " PassThroughMode " + encoder_Settings.p

	applyStr += ">> PID 512 EncoderType 3 PassThroughMode 0 Bitrate 2 AudioDelay 90 EncodedAudioVolumeAdjustEnable 0 EncodedAudioVolume 0x7fffffff\n";

	applyStr += "AAC\n";
	applyStr += ">> EncoderVersion " + encoder_Settings.Encoder_Version;
	applyStr += " CRCmode " + encoder_Settings.Error_Correction_Mode;
	applyStr += " Profile " + encoder_Settings.Profile;
	applyStr += " \n";

	applyStr += "TMX\n";
	applyStr += ">> BitRate " + encoder_Settings.MUX;
	applyStr += " \n";

	applyStr += "TCP\n";
	applyStr += ">> setMode 2 IPaddress " + encoder_Settings.Public_Network.IP_Address;
	applyStr += " NetMask " + encoder_Settings.Public_Network.Subnet;
	applyStr += " Gateway " + encoder_Settings.Public_Network.Gateway;
	applyStr += " dns " + encoder_Settings.Public_Network.DNS;
	applyStr += " \n";

	applyStr += "RTP\n";
	applyStr += ">> OperationMode 1 TransportType 1 CastType " + encoder_Settings.Output_Cast_Type;
	applyStr += " TargetIP " + encoder_Settings.Output_IP;
	applyStr += " Port " + encoder_Settings.Output_Port;
	applyStr += " ttl " + encoder_Settings.TTL;
	applyStr += " \n";

	applyStr += "CNL\n";
	applyStr += ">> command 5\n";
	applyStr += "CNL\n";
	applyStr += ">> command 2\n";

	//Save the apply script
	util.WriteToFile((char *)"/settings/apply", applyStr.c_str());
	return result;
}
Encoder_Settings Encoder_Settings_Manager::get_Encoder_Settings(int ID)
{
	Encoder_Settings encoder_Settings;
	for (Encoder_Settings_Iterator = Encoder_Settings_List.begin(); Encoder_Settings_Iterator != Encoder_Settings_List.end(); Encoder_Settings_Iterator++)
	{
		if(Encoder_Settings_Iterator->ID == ID)
		{
			encoder_Settings = Encoder_Settings(*Encoder_Settings_Iterator);
		}
	}
	return encoder_Settings;
}

void Encoder_Settings_Manager::print_Encoder_Settings(int ID)
{
	Encoder_Settings encoder_Settings;
	for (Encoder_Settings_Iterator = Encoder_Settings_List.begin(); Encoder_Settings_Iterator != Encoder_Settings_List.end(); Encoder_Settings_Iterator++)
	{
		if(Encoder_Settings_Iterator->ID == ID)
		{
			encoder_Settings = Encoder_Settings(*Encoder_Settings_Iterator);
		}
	}

	cout << "ID " << encoder_Settings.ID << endl;

	//Input
	cout << "Video_Source " << encoder_Settings.Video_Source << endl;
	cout << "Video_Capture " << encoder_Settings.Video_Capture << endl;
	cout << "Width " << encoder_Settings.Width << endl;
	cout << "Height " << encoder_Settings.Height << endl;
	cout << "Video_FrameRate " << encoder_Settings.Video_FrameRate << endl;
	cout << "Video_Format " << encoder_Settings.Video_Format << endl;
	cout << "Audio_Source " << encoder_Settings.Audio_Source << endl;
	cout << "Audio_Coding " << encoder_Settings.Audio_Coding << endl;

	//Preprocessing
	cout << "Inverse_Telecine " << encoder_Settings.Inverse_Telecine << endl;
	cout << "Transcode_To_SD " << encoder_Settings.Transcode_To_SD << endl;
	cout << "Output_Width " << encoder_Settings.Output_Width << endl;
	cout << "Output_Height " << encoder_Settings.Output_Height << endl;
	cout << "Output_FrameRate " << encoder_Settings.Output_FrameRate << endl;

	//Encoder
	cout << "Matrix_Cast_Video_Engine " << encoder_Settings.Matrix_Cast_Video_Engine << endl;
	cout << "Horizontal_Rescaled_Resolution " << encoder_Settings.Horizontal_Rescaled_Resolution << endl;
	cout << "Video_Bitrate " << encoder_Settings.Video_Bitrate << endl;
	cout << "Profile " << encoder_Settings.Profile << endl;
	cout << "Encoder_Version " << encoder_Settings.Encoder_Version << endl;
	cout << "Error_Correction_Mode " << encoder_Settings.Error_Correction_Mode << endl;
	cout << "Audio_Delay " << encoder_Settings.Audio_Delay << endl;
	cout << "Encoding_Mode " << encoder_Settings.Encoding_Mode << endl;
	cout << "GOP_Size " << encoder_Settings.GOP_Size << endl;
	cout << "Video_Engine_Quality " << encoder_Settings.Video_Engine_Quality << endl;
	cout << "Picture_Quality " << encoder_Settings.Picture_Quality << endl;
	cout << "Aspect_Ratio " << encoder_Settings.Aspect_Ratio << endl;
	cout << "Audio_Bitrate " << encoder_Settings.Audio_Bitrate << endl;
	cout << "Audio_Type " << encoder_Settings.Audio_Type << endl;
	cout << "Audio_Profile " << encoder_Settings.Audio_Profile << endl;
	cout << "IDR_Frequency " << encoder_Settings.IDR_Frequency << endl;
	cout << "Fast_Channel_Changing " << encoder_Settings.Fast_Channel_Changing << endl;
	cout << "Adjust_Input_Audio " << encoder_Settings.Adjust_Input_Audio << endl;
	cout << "Volumn_Control " << encoder_Settings.Volumn_Control << endl;
	cout << "Loop_Filter " << encoder_Settings.Loop_Filter << endl;
	cout << "Loop_Filter_Alpha " << encoder_Settings.Loop_Filter_Alpha << endl;
	cout << "Loop_Filter_Beta " << encoder_Settings.Loop_Filter_Beta << endl;
	cout << "MUX " << encoder_Settings.MUX << endl;
	cout << "MAX " << encoder_Settings.MAX << endl;
	cout << "Video_PID " << encoder_Settings.Video_PID << endl;
	cout << "Audio_PID " << encoder_Settings.Audio_PID << endl;

	//Output
	cout << "Output_Cast_Type " << encoder_Settings.Output_Cast_Type << endl;
	cout << "Output_IP " << encoder_Settings.Output_IP << endl;
	cout << "Output_Port " << encoder_Settings.Output_Port << endl;
	cout << "TTL " << encoder_Settings.TTL << endl;
	cout << "Public IP " << encoder_Settings.Public_Network.IP_Address << endl;
	cout << "Public Subnet " << encoder_Settings.Public_Network.Subnet << endl;
	cout << "Public Gateway " << encoder_Settings.Public_Network.Gateway << endl;
	cout << "Public DNS " << encoder_Settings.Public_Network.DNS << endl;
}

Encoder_Settings_Manager::~Encoder_Settings_Manager()
{
	// TODO Auto-generated destructor stub
}

