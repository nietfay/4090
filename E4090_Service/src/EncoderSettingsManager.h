/*
 * EncoderSettingsManager.h
 *
 *  Created on: 2012-02-17
 *      Author: user
 */
#include "EncoderSettings.h"
#include <list>
#include "Utility.h"

#ifndef ENCODERSETTINGSMANAGER_H_
#define ENCODERSETTINGSMANAGER_H_

class Encoder_Settings_Manager
{
	public:
		Encoder_Settings_Manager();
		//Add Encoder_Settings to this manager
		bool add_Encoder_Settings(Encoder_Settings encoder_Settings);
		//Remove Encoder_Settings from this manager
		bool remove_Encoder_Settings(int ID);
		//Apply Encoder_Settings by it's ID
		bool apply_Encoder_Settings(int ID);
		//Return an Encoder_Settings by it's ID
		Encoder_Settings get_Encoder_Settings(int ID);

		/* DEBUG FUNCTIONS */
		void print_Encoder_Settings(int ID);


		virtual ~Encoder_Settings_Manager();

		//Variables
		Encoder_Settings Default_Encoder_Settings;
		list<Encoder_Settings> Encoder_Settings_List;
		list<Encoder_Settings>::iterator Encoder_Settings_Iterator;
};

#endif /* ENCODERSETTINGSMANAGER_H_ */
