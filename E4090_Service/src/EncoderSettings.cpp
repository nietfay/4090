/*
 * EncoderSettings.cpp
 *
 *  Created on: 2012-02-13
 *      Author: user
 */

#include "EncoderSettings.h"

Encoder_Settings::Encoder_Settings()
{
	// TODO Auto-generated constructor stub
	ID = 0;

	Video_Source = 7;							//Component = 2, SDI = 6, **HDMI = 7
	Video_Capture = 0;							//**1080i = 0, 720p = 1, 480i = 2, 525i = 3
	Width = 1920;								//WidthxHeight **1920x1080, 1280x720, 720x480, 720x576
	Height = 1080;
	Video_FrameRate = 5;						//23.976 = 1, 24 = 2, 25 = 3, 29.976 = 4, **30 = 5, 50 = 6, 59.976 = 7, 60 = 8
	Video_Format = 1;							//**Interlace = 1, Progressive = 2, PSF = 3
	Audio_Source = 3;							//(HD and SD)RCA = 0, (HD and SD)SDPIF = 1, (HD)SDI = 2, **(HD)HDMI = 3
	Audio_Coding = 2;							//44100 = 1, **48000 = 2

	Inverse_Telecine = 1;						//**On = 1, Off = 0
	Transcode_To_SD = 0;						//On = 1, **Off = 0
	Output_Width = 720;							//WidthxHeight 160x90, 160x120, 320x180, 320,240, 352x288, **720x480(NTSC), 720x576(PAL)
	Output_Height = 480;
	Output_FrameRate = 4;						//5 = 12, 10 = 11, 12 = 10, 15 = 9, 23.97 = 1, 24 = 2, 25 = 3, **29.94 = 4, 30 = 5

	Matrix_Cast_Video_Engine = 1;        		//(Rate Control) Ultra High = 2, **High = 1, Standard = 0
	Horizontal_Rescaled_Resolution = 1440;		//This value is set automatically based on the Video Bitrate and the Height
												/*
													Video Capture [height] 1080i/1080p

													If VideoBitRate is set to the following
													1300,1500,1700,2000,2499 – [HorizontalRescaledResolution] 1280
													2500,2700,3000,3499 – [HorizontalRescaledResolution] 1440
													3500,3700,4000,4500,5000,6000,7000,8000 – [HorizontalRescaledResolution] 1920

													Video Capture  [height] 720p

													If VideoBitRate is set to the following
													1300,1500,1700,2000,2499 – [HorizontalRescaledResolution] 960
													2500,2700,3000,3499 – [HorizontalRescaledResolution] 1280
													3500,3700,4000,4500,5000,6000,7000,8000 – [HorizontalRescaledResolution] 1280

													Video Capture  [height] 480i/576i

													If VideoBitRate is set to the following
													300, 399 - [HorizontalRescaledResolution] 352
													400, 699 - [HorizontalRescaledResolution] 544
													700,800,900,1000,1200,1400 – [HorizontalRescaledResolution] 720
												 */
	Video_Bitrate = 3000000;					//For HD 1000kpbs - 8000kbps **3000kbps, For SD 250kbps - 1400kbps **750kbps
	Video_Engine_Quality = 250;					//This is for calculation only For HD 100 - 2000 **250, For SD 50 - 1000 **250
	Picture_Quality = 7;						//(Use Only when Matrix_Cast_Video_Engine = 2)1 - 14 **7
	Audio_Type = 4;								//**LC-AAC = 4, HE-AAC = 3(License Only), AC-3 Pass Through = 11(SDPIF Only)
	Audio_Profile = 0;							//**LC-AAC = 0, HE-AAC = 1
	Encoder_Version = 0;						//**MPEG2 = 0, MPEG4 = 1
	Error_Correction_Mode = 1;					//Off = 0, **On = 1
	Adjust_Input_Audio = 1;						//Off = 0, **On = 1
	Volumn_Control = 1;							//0x00000000 = 0, **0x1fffffff = 1, 0x3fffffff = 2, 0x5fffffff = 3, 0x7fffffff = 4
	Audio_Bitrate = 2;							//32kbps = 0, 48kbps = 1, **56kbps = 2, 64kbps = 3, 80kbps = 4, 96kbps = 5, 112kbps = 6, 128kbps = 7
												//160kbps = 8, 192kbps = 9, 224kbps = 10, 256kbps = 11, 320kbps = 12, 384kbps = 13
	Encoding_Mode = 0;							//**Automatic = 0, Frame = 1, MBAFF = 2, PAFF = 3
	GOP_Size = 25;								//1 - 300 **25
	Audio_Delay = 0;							//**0 = 0, 90 = 1
	Profile = 4;								//**High = 4, Main = 3, Base = 0
	Aspect_Ratio = 2; 							//4x3 = 1, **16x9 = 2, 1x1 = 3, 2.34x1 = 4
	IDR_Frequency = 1;							//IDR_Frequency is based on Fast_Channel_Changing, only ON if IDR is 1 **On = 1, Off = 0
	Fast_Channel_Changing = 1;					//**On = 1, Off = 0
	Loop_Filter = 0;							//On Across Slice Boundries = 2, On = 1, **Off = 0
	Loop_Filter_Alpha = -2;						//-6 to 6 **-2
	Loop_Filter_Beta =  -1;						//-6 to 6 **-1
	MUX = 4600000;								//Bitrate = MaxVideoBitRate +  500000 for VBR
	MAX = 4000000;								/*MaxVideoBitrate = Video_BitRate + Audio_Bitrate(round up) +  Video_Engine_Quality
												Note: Audio bitrate need to be converted o bits.
												Ie: 320kbps = 320000 = 400000 (round up)
													56kbps = 56000 = 100000 (round up to the hundred)
												 */
	Video_PID = 256;							//1 - 1024 **256
	Audio_PID = 512;							//1 - 1024 **512
	Output_Cast_Type = 1;						//**Unicast = 1, Multicast = 2
	Output_IP = "234.5.5.5";					//234.5.5.5
	Output_Port = 5500;							//5500
	TTL = 64;									//64
	Public_Network = Public_Port();
}

Encoder_Settings::Encoder_Settings(const Encoder_Settings& E_S)
{
	this->ID = E_S.ID;

	//Input
	this->Video_Source = E_S.Video_Source;
	this->Video_Capture = E_S.Video_Capture;
	this->Width = E_S.Width;
	this->Height = E_S.Height;
	this->Video_FrameRate = E_S.Video_FrameRate;
	this->Video_Format = E_S.Video_Format;
	this->Audio_Source = E_S.Audio_Source;
	this->Audio_Coding = E_S.Audio_Coding;

	//Preprocessing
	this->Inverse_Telecine = E_S.Inverse_Telecine;
	this->Transcode_To_SD = E_S.Transcode_To_SD;
	this->Output_Width = E_S.Output_Width;
	this->Output_Height = E_S.Output_Height;
	this->Output_FrameRate = E_S.Output_FrameRate;

	//Encoder
	this->Matrix_Cast_Video_Engine = E_S.Matrix_Cast_Video_Engine;
	this->Horizontal_Rescaled_Resolution = E_S.Horizontal_Rescaled_Resolution;
	this->Video_Bitrate = E_S.Video_Bitrate;
	this->Profile = E_S.Profile;
	this->Encoder_Version = E_S.Encoder_Version;
	this->Error_Correction_Mode = E_S.Error_Correction_Mode;
	this->Audio_Delay = E_S.Audio_Delay;
	this->Encoding_Mode = E_S.Encoding_Mode;
	this->GOP_Size = E_S.GOP_Size;
	this->Video_Engine_Quality = E_S.Video_Engine_Quality;
	this->Picture_Quality = E_S.Picture_Quality;
	this->Aspect_Ratio = E_S.Aspect_Ratio;
	this->Audio_Bitrate = E_S.Audio_Bitrate;
	this->Audio_Type = E_S.Audio_Type;
	this->Audio_Profile = E_S.Audio_Profile;
	this->IDR_Frequency = E_S.IDR_Frequency;
	this->Fast_Channel_Changing = E_S.Fast_Channel_Changing;
	this->Adjust_Input_Audio = E_S.Adjust_Input_Audio;
	this->Volumn_Control = E_S.Volumn_Control;
	this->Loop_Filter = E_S.Loop_Filter;
	this->Loop_Filter_Alpha =  E_S.Loop_Filter_Alpha;
	this->Loop_Filter_Beta =  E_S.Loop_Filter_Beta;
	this->MUX = E_S.MUX;
	this->MAX = E_S.MAX;
	this->Video_PID = E_S.Video_PID;
	this->Audio_PID =  E_S.Audio_PID;

	//Output
	this->Output_Cast_Type = E_S.Output_Cast_Type;
	this->Output_IP = E_S.Output_IP;
	this->Output_Port = E_S.Output_Port;
	this->TTL = E_S.TTL;
	this->Public_Network = E_S.Public_Network;

}

bool Encoder_Settings::get_Encoder_Settings()
{
	pugi::xml_document doc;
	pugi::xml_parse_result xmlResult = doc.load_file("/settings/Encoder_1.xml");
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
	pugi::xml_node Input = Root.child("Input");
	pugi::xml_node Preprocessing = Root.child("Preprocessing");
	pugi::xml_node Encoder = Root.child("Encoder");
	pugi::xml_node Output = Root.child("Output");
	pugi::xml_node System = Root.child("System");

	//ID will always be 0 now since there is only 1 Settings
	this->ID = 0;

	//Input
	pugi::xml_node VideoSource = Input.child("videosource");
	this->Video_Source = atoi(VideoSource.first_child().value());

	pugi::xml_node VideoCapture = Input.child("capture").child("videocapture");
	this->Video_Capture = atoi(VideoCapture.first_child().value());

	pugi::xml_node Width = Input.child("capture").child("Width");
	this->Width = atoi(Width.first_child().value());
	pugi::xml_node Height = Input.child("capture").child("Height");
	this->Height = atoi(Height.first_child().value());

	pugi::xml_node FrameRate = Input.child("FrameRate");
	this->Video_FrameRate = atoi(FrameRate.first_child().value());

	pugi::xml_node VideoFormat = Input.child("VideoFormat");
	this->Video_Format = atoi(VideoFormat.first_child().value());

	pugi::xml_node AudioSourceInput = Input.child("audiosourceinput");
	this->Audio_Source = atoi(AudioSourceInput.first_child().value());

	pugi::xml_node AudioCoding = Input.child("audiocoding");
	this->Audio_Coding = atoi(AudioCoding.first_child().value());

	//Preprocessing
	pugi::xml_node InverseTelecine = Preprocessing.child("InverseTelecine");
	this->Inverse_Telecine = atoi(InverseTelecine.first_child().value());

	pugi::xml_node TranscodeToSD = Preprocessing.child("TranscodeToSD");
	this->Transcode_To_SD = atoi(TranscodeToSD.first_child().value());

	pugi::xml_node OutputWidth = Preprocessing.child("OutputWidth");
	this->Output_Width = atoi(OutputWidth.first_child().value());

	pugi::xml_node OutputHeight = Preprocessing.child("OutputHeight");
	this->Output_Height = atoi(OutputHeight.first_child().value());

	pugi::xml_node OutputFrameRate = Preprocessing.child("OutputFrameRate");
	this->Output_FrameRate =  atoi(OutputFrameRate.first_child().value());

	//Encoder
	pugi::xml_node MatrixCastVideoEngine = Encoder.child("RateControl");
	this->Matrix_Cast_Video_Engine = atoi(MatrixCastVideoEngine.first_child().value());

	pugi::xml_node HorizontalRescaledResolution = Encoder.child("HorizontalRescaledResolution");
	this->Horizontal_Rescaled_Resolution = atoi(HorizontalRescaledResolution.first_child().value());

	pugi::xml_node VideoBitrate = Encoder.child("VideoBitRate");
	this->Video_Bitrate = atoi(VideoBitrate.first_child().value());

	pugi::xml_node Profile = Encoder.child("Profile");
	this->Profile = atoi(Profile.first_child().value());

	pugi::xml_node EncoderVersion = Encoder.child("EncoderVersion");
	this->Encoder_Version = atoi(EncoderVersion.first_child().value());

	pugi::xml_node ErrorCorrection = Encoder.child("CRC");
	this->Error_Correction_Mode = atoi(ErrorCorrection.first_child().value());

	pugi::xml_node AudioDelay = Encoder.child("audioDelay");
	this->Audio_Delay = atoi(AudioDelay.first_child().value());

	pugi::xml_node EncodingMode = Encoder.child("EncodingMode");
	this->Encoding_Mode = atoi(EncodingMode.first_child().value());

	pugi::xml_node GOP = Encoder.child("GOP");
	this->GOP_Size = atoi(GOP.first_child().value());

	pugi::xml_node VEQ = Encoder.child("VEQ");
	this->Video_Engine_Quality = atoi(VEQ.first_child().value());

	pugi::xml_node PQ = Encoder.child("PQ");
	this->Picture_Quality = atoi(PQ.first_child().value());

	pugi::xml_node AspectRatio = Encoder.child("AspectRatio");
	this->Aspect_Ratio = atoi(AspectRatio.first_child().value());

	pugi::xml_node AudioType = Encoder.child("EncoderType");
	this->Audio_Type = atoi(AudioType.first_child().value());

	pugi::xml_node AudioProfile = Encoder.child("AudioProfile");
	this->Audio_Profile = atoi(AudioProfile.first_child().value());

	pugi::xml_node IDRFrequency = Encoder.child("IDRFrequency");
	this->IDR_Frequency = atoi(IDRFrequency.first_child().value());

	pugi::xml_node ChannelChange = Encoder.child("ChannelChange");
	this->Fast_Channel_Changing = atoi(ChannelChange.first_child().value());

	pugi::xml_node EncodedAudioVolumeAdjustEnable = Encoder.child("EncodedAudioVolumeAdjustEnable");
	this->Adjust_Input_Audio = atoi(EncodedAudioVolumeAdjustEnable.first_child().value());

	pugi::xml_node AdjustVolume = Encoder.child("EncodedAudioVolume");
	this->Volumn_Control = atoi(AdjustVolume.first_child().value());

	pugi::xml_node LoopFilter = Encoder.child("LoopFilter");
	this->Loop_Filter = atoi(LoopFilter.first_child().value());

	pugi::xml_node LoopFilterAlpha = Encoder.child("LoopFilterAlpha");
	this->Loop_Filter_Alpha = atoi(LoopFilterAlpha.first_child().value());

	pugi::xml_node LoopFilterBeta = Encoder.child("LoopFilterBeta");
	this->Loop_Filter_Beta = atoi(LoopFilterBeta.first_child().value());

	pugi::xml_node VPID = Encoder.child("VPID");
	this->Video_PID = atoi(VPID.first_child().value());

	pugi::xml_node APID = Encoder.child("APID");
	this->Audio_PID = atoi(APID.first_child().value());

	pugi::xml_node MUX = Encoder.child("MUX");
	this->MUX = atoi(MUX.first_child().value());

	pugi::xml_node MAX = Encoder.child("MAX");
	this->MAX = atoi(MAX.first_child().value());

	//Output
	pugi::xml_node CastType = Output.child("CastType");
	this->Output_Cast_Type = atoi(CastType.first_child().value());

	//System
	pugi::xml_node OutputIP = System.child("TargetIP");
	this->Output_IP = (string)OutputIP.first_child().value();

	pugi::xml_node OutputPort = System.child("TargetPort");
	this->Output_Port = atoi(OutputPort.first_child().value());

	pugi::xml_node TTL = System.child("TargetTTL");
	this->TTL = atoi(TTL.first_child().value());

	pugi::xml_node IPAddress = System.child("IPAddress");
	this->Public_Network.IP_Address = (string)IPAddress.first_child().value();

	pugi::xml_node Gateway = System.child("DefaultGateway");
	this->Public_Network.Gateway = (string)Gateway.first_child().value();

	pugi::xml_node Subnet = System.child("SubnetMask");
	this->Public_Network.Subnet = (string)Subnet.first_child().value();

	pugi::xml_node DNS = System.child("DNS");
	this->Public_Network.DNS = (string)DNS.first_child().value();
	return true;
}

void Encoder_Settings::set_Encoder_Settings(int id, int video_Source, int video_Capture, int width, int height, int video_FrameRate, int video_Format, int audio_Source,
						      	  	  	    int audio_Coding, int inverse_Telecine, int transcode_To_SD, int output_Width, int output_Height, int output_FrameRate,
						      	  	  	    int matrix_Cast_Video_Engine, int horizontal_Rescaled_Resolution, int video_Bitrate, int video_Engine_Quality,
						      	  	  	    int picture_Quality, int audio_Type, int audio_Profile, int encoder_Version, int error_Correction_Mode, int adjust_Input_Audio,
						      	  	  	    int volumn_Control, int audio_Bitrate, int encoding_Mode, int gop_Size, int audio_Delay, int profile, int aspect_Ratio,
						      	  	  	    int idr_Frequency, int fast_Channel_Changing, int loop_Filter, int loop_Filter_Alpha, int loop_Filter_Beta, int mux, int max,
						      	  	  	    int video_PID, int audio_PID, int output_Cast_Type, string output_IP, int output_Port, int ttl,string public_IP, string public_Subnet,
										    string public_Gateway, string public_DNS)
{
	this->ID = id;
	this->Video_Source = video_Source;
	this->Video_Capture = video_Capture;
	this->Width = width;
	this->Height = height;
	this->Video_FrameRate = video_FrameRate;
	this->Video_Format = video_Format;
	this->Audio_Source = audio_Source;
	this->Audio_Coding = audio_Coding;
	this->Inverse_Telecine = inverse_Telecine;
	this->Transcode_To_SD = transcode_To_SD;
	this->Output_Width = output_Width;
	this->Output_Height = output_Height;
	this->Output_FrameRate = output_FrameRate;
	this->Matrix_Cast_Video_Engine = matrix_Cast_Video_Engine;
	this->Horizontal_Rescaled_Resolution = horizontal_Rescaled_Resolution;
	this->Video_Bitrate = video_Bitrate;
	this->Video_Engine_Quality = video_Engine_Quality;
	this->Picture_Quality = picture_Quality;
	this->Audio_Type = audio_Type;
	this->Audio_Profile = audio_Profile;
	this->Encoder_Version = encoder_Version;
	this->Error_Correction_Mode = error_Correction_Mode;
	this->Adjust_Input_Audio = adjust_Input_Audio;
	this->Volumn_Control = volumn_Control;
	this->Audio_Bitrate = audio_Bitrate;
	this->Encoding_Mode = encoding_Mode;
	this->GOP_Size = gop_Size;
	this->Audio_Delay = audio_Delay;
	this->Profile = profile;
	this->Aspect_Ratio = aspect_Ratio;
	this->IDR_Frequency = idr_Frequency;
	this->Fast_Channel_Changing = fast_Channel_Changing;
	this->Loop_Filter = loop_Filter;
	this->Loop_Filter_Alpha = loop_Filter_Alpha;
	this->Loop_Filter_Beta = loop_Filter_Beta;
	this->MUX = mux;
	this->MAX = max;
	this->Video_PID = video_PID;
	this->Audio_PID = audio_PID;
	this->Output_Cast_Type = output_Cast_Type;
	this->Output_IP = output_IP;
	this->Output_Port = output_Port;
	this->TTL = ttl;
	this->Public_Network.IP_Address = public_IP;
	this->Public_Network.Subnet = public_Subnet;
	this->Public_Network.Gateway = public_Gateway;
	this->Public_Network.DNS = public_DNS;
}

Encoder_Settings::~Encoder_Settings()
{
	// TODO Auto-generated destructor stub
}

