#ifndef _MAILINTERFACE_H
#define _MAILINTERFACE_H

#include "Pop3Adaptor.h"
#include <string>

using namespace std;
class MailInterface	
{
private:
	
	Pop3Adaptor _server;	//currect server
public:
	MailInterface(const string& fileName);        //conversion Ctor,I don't need here copy Ctor
	bool authorization();	                     //sync with the server's authorization phase
	void screenMenu();							//screen interface to control the client
};

#endif