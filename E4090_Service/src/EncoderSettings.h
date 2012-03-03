/*
 * EncoderSettings.h
 *
 *  Created on: 2012-02-13
 *      Author: user
 */
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "pugixml.hpp"
#include "PublicPort.h"
using namespace std;

#ifndef ENCODERSETTINGS_H_
#define ENCODERSETTINGS_H_


class Encoder_Settings {
public:
	Encoder_Settings();
	//Copy Constructor
	Encoder_Settings(const Encoder_Settings& E_S);
	//Read into the xml file and get this Encoder_Settings info
	bool get_Encoder_Settings();
	//Set and save this settings to xml file
	void set_Encoder_Settings(int id, int video_Source, int video_Capture, int width, int height, int video_FrameRate, int video_Format, int audio_Source,
						      int audio_Coding, int inverse_Telecine, int transcode_To_SD, int output_Width, int output_Height, int output_FrameRate,
						      int matrix_Cast_Video_Engine, int horizontal_Rescaled_Resolution, int video_Bitrate, int video_Engine_Quality,
						      int picture_Quality, int audio_Type, int audio_Profile, int encoder_Version, int error_Correction_Mode, int adjust_Input_Audio,
						      int volumn_Control, int audio_Bitrate, int encoding_Mode, int gop_Size, int audio_Delay, int profile, int aspect_Ratio,
						      int idr_Frequency, int fast_Channel_Changing, int loop_Filter, int loop_Filter_Alpha, int loop_Filter_Beta, int mux, int max,
						      int video_PID, int audio_PID, int output_Cast_Type, string output_IP, int output_Port, int ttl, string public_IP, string public_Subnet,
						      string public_Gateway, string public_DNS);

	virtual ~Encoder_Settings();

	//Variables								//** is Default Value
	int ID;
	int Video_Source;						//Component = 2, SDI = 6, **HDMI = 7
	int Video_Capture;						//**1080i = 0, 720p = 1, 480i = 2, 525i = 3
	int Width;								//WidthxHeight **1920x1080, 1280x720, 720x480, 720x576
	int Height;
	int Video_FrameRate;					//23.976 = 1, 24 = 2, 25 = 3, 29.976 = 4, **30 = 5, 50 = 6, 59.976 = 7, 60 = 8
	int Video_Format;						//**Interlace = 1, Progressive = 2, PSF = 3
	int Audio_Source;						//(HD and SD)RCA = 0, (HD and SD)SDPIF = 1, (HD)SDI = 2, **(HD)HDMI = 3
	int Audio_Coding;						//44100 = 1, **48000 = 2
	int Inverse_Telecine;					//**On = 1, Off = 0
	int Transcode_To_SD;					//On = 1, **Off = 0
	int Output_Width;						//WidthxHeight 160x90, 160x120, 320x180, 320,240, 352x288, **720x480(NTSC), 720x576(PAL)
	int Output_Height;
	int Output_FrameRate;					//5 = 12, 10 = 11, 12 = 10, 15 = 9, 23.97 = 1, 24 = 2, 25 = 3, **29.94 = 4, 30 = 5
	int Matrix_Cast_Video_Engine;        	//(Rate Control) Ultra High = 2, **High = 1, Standard = 0

	int Horizontal_Rescaled_Resolution;		//This value is set automatically based on the Video Bitrate and the Height
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
	int Video_Bitrate;						//For HD 1000kpbs - 8000kbps **3000kbps, For SD 250kbps - 1400kbps **750kbps
	int Video_Engine_Quality;				//This is for calculation only For HD 100 - 2000 **250, For SD 50 - 1000 **250
	int Picture_Quality;					//(Only when Matrix_Cast_Video_Engine = 2)1 - 14 **7
	int Audio_Type;							//**LC-AAC = 4, HE-AAC = 3(License Only), AC-3 Pass Through = 11(SDPIF Only)
	int Audio_Profile;						//**LC-AAC = 0, HE-AAC = 1
	int Encoder_Version;					//**MPEG2 = 0, MPEG4 = 1
	int Error_Correction_Mode;				//Off = 0, **On = 1
	int Adjust_Input_Audio;					//Off = 0, **On = 1
	int Volumn_Control;						//0x00000000 = 0, **0x1fffffff = 1, 0x3fffffff = 2, 0x5fffffff = 3, 0x7fffffff = 4
	int Audio_Bitrate;						//32kbps = 0, 48kbps = 1, **56kbps = 2, 64kbps = 3, 80kbps = 4, 96kbps = 5, 112kbps = 6, 128kbps = 7
											//160kbps = 8, 192kbps = 9, 224kbps = 10, 256kbps = 11, 320kbps = 12, 384kbps = 13
	int Encoding_Mode;						//**Automatic = 0, Frame = 1, MBAFF = 2, PAFF = 3
	int GOP_Size;							//1 - 300 **25
	int Audio_Delay;						//**0 = 0, 90 = 1
	int Profile;							//**High = 4, Main = 3, Base = 0
	int Aspect_Ratio;						//4x3 = 1, **16x9 = 2, 1x1 = 3, 2.34x1 = 4
	int IDR_Frequency;						//IDR_Frequency is based on Fast_Channel_Changing, only ON if IDR is 1 **On = 1, Off = 0
	int Fast_Channel_Changing;				//**On = 1, Off = 0
	int Loop_Filter;						//On Across Slice Boundries = 2, On = 1, **Off = 0
	int Loop_Filter_Alpha;					//-6 to 6 **-2
	int Loop_Filter_Beta;					//-6 to 6 **-1
	int MUX;								//Bitrate = MaxVideoBitRate +  500000 for VBR
	int MAX;								/*MaxVideoBitrate = Video_BitRate + Audio_Bitrate(round up) +  Video_Engine_Quality
											Note: Audio bitrate need to be converted into bits.
											Ie: 320kbps = 320000 = 400000 (round up)
												56kbps = 56000 = 100000 (round up to the hundred)
	 	 	 	 	 	 	 	 	 	 	 */
	int Video_PID;							//1 - 1024 **256
	int Audio_PID;							//1 - 1024 **512
	int Output_Cast_Type;					//**Unicast = 1, Multicast = 2
	string Output_IP;						//234.5.5.5
	int Output_Port;						//5500
	int TTL;								//64
	Public_Port Public_Network;				/*
											IP: 192.168.1.200
											Subnet: 255.255.255.0
											Gateway: 192.168.1.1
											DNS: 192.168.1.1
											*/

};

#endif /* ENCODERSETTINGS_H_ */
