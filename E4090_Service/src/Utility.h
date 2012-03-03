/*
 * Utility.h
 *
 *  Created on: 2012-02-14
 *      Author: user
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>
#include <fstream>

using namespace std;

class Utility
{
	public:
		Utility();
		char * RunScript(char * ScriptPath);
		bool WriteToFile(char * FilePath, const char * Content);
		virtual ~Utility();
};

#endif /* UTILITY_H_ */
