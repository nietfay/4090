/*
 * TCPServer.cpp
 *
 *  Created on: 2012-02-17
 *      Author: user
 */

#include "TCPServer.h"
#include <netdb.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAXHOSTNAME 256

TCP_Server::TCP_Server()
{
	// TODO Auto-generated constructor stub
	this->Port = 30000;
	bzero(this->RecBuf, sizeof(this->RecBuf));
	bzero(this->SendBuf, sizeof(this->SendBuf));
}

void TCP_Server::Init_Server()
{
	struct sockaddr_in socketInfo;
	char sysHost[MAXHOSTNAME + 1]; // Hostname of this computer we are running on
	struct hostent	*hPtr;

	bzero(&socketInfo, sizeof(sockaddr_in)); // Clear structure memory

	// Get system information

	gethostname(sysHost, MAXHOSTNAME); // Get the name of this computer we are running on
	if ((hPtr = gethostbyname(sysHost)) == NULL)
	{
		cerr << "System Hostname Misconfigured." << endl;
		exit(EXIT_FAILURE);
	}

	// create socket

	if ((this->sID = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		close(this->sID);
		exit(EXIT_FAILURE);
	}

	// Binding to the already used socket

	// Load system information into socket data structures

	socketInfo.sin_family = AF_INET;
	//socketInfo.sin_addr.s_addr = htonl(INADDR_ANY); // Use any address available to the system
	socketInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
	socketInfo.sin_port = htons(this->Port); // Set port number

	// set SO_REUSEADDR on a socket to true (1):
	int optval = 1;
	setsockopt(this->sID, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

	// Bind the socket to a local socket address
	if (bind(this->sID, (struct sockaddr *) &socketInfo, sizeof(socketInfo))< 0)
	{
		close(this->sID);
		perror("bind");
		exit(EXIT_FAILURE);
	}

	int iSocketOption = 0;
	socklen_t iSocketOptionLen = sizeof(socklen_t);

	getsockopt(this->sID, SOL_SOCKET, SO_REUSEADDR, (char *) &iSocketOption,&iSocketOptionLen);

	listen(this->sID, 1);
}

bool TCP_Server::TCP_Accept()
{
	int socketConnection;
	if ((socketConnection = accept(this->sID, NULL, NULL)) < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string TCP_Server::TCP_Recv()
{
	string RecStr;
	read(this->sID, this->RecBuf, this->RecBufSize);
	bzero(this->RecBuf, sizeof(this->RecBuf));
	RecStr = (string)this->RecBuf;
	return RecStr;
}

bool TCP_Server::TCP_Send(string Message)
{
	Message.copy(this->SendBuf, sizeof(Message));
	write(this->sID, this->SendBuf, sizeof(this->SendBuf));
	bzero(this->SendBuf, sizeof(this->SendBuf));
	return true;
}

TCP_Server::~TCP_Server()
{
	// TODO Auto-generated destructor stub
}

