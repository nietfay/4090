/*
 * TCPServer.h
 *
 *  Created on: 2012-02-17
 *      Author: user
 */
#include <stdio.h>
#include <string>
using namespace std;

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

class TCP_Server
{
public:
	TCP_Server();
	//Init TCPServer Class
	void Init_Server();
	//Accept a TCP Connection
	bool TCP_Accept();
	//Send a message/command to the client
	bool TCP_Send(string Message);
	//Receive message/request from client
	string TCP_Recv();

	virtual ~TCP_Server();

	//Variable
	int sID;
	int Port;
	static const int RecBufSize = 1024;
	char RecBuf[RecBufSize];
	static const int SendBufSize = 1024;
	char SendBuf[SendBufSize];
};

#endif /* TCPSERVER_H_ */
