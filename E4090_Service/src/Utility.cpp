/*
 * Utility.cpp
 *
 *  Created on: 2012-02-14
 *      Author: user
 */

#include "Utility.h"

Utility::Utility()
{
	// TODO Auto-generated constructor stub

}

char * Utility::RunScript(char * ScriptPath)
{
	FILE * fp;
	fp = popen(ScriptPath, "r");
	char * p = NULL;
	if(fp)
	{
		size_t n;
		getline(&p, &n, fp);
	}
	pclose(fp);
	return p;
}

bool Utility::WriteToFile(char * FilePath, const char * Content)
{
	ofstream myoutfile(FilePath);
	if (myoutfile.is_open())
	{
		myoutfile << Content;
	}
	else
	{
		return false;
	}
	myoutfile.close();
	return true;
}

Utility::~Utility()
{
	// TODO Auto-generated destructor stub
}

