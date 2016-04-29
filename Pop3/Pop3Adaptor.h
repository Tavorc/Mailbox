#ifndef _POP3ADAPTOR_H
#define _POP3ADAPTOR_H
#include <iostream> 
#include <string.h>
#include "Acount.h"

using namespace std;




/// This class responsible to fetch and management your mailbox.
/// this implemenation will the mail box stoarge will base on a file systems.

class Pop3Adaptor
{
private:
	Acount _acount;
	bool _user;
	bool _pass;
	bool _connected;
	// what ever you need.

public:
	Pop3Adaptor(const string& fileName);           //convarsion Ctor I don't need here copy Ctor
	Pop3Adaptor& operator=(const Pop3Adaptor& server); //opr =

					
	/* USER userid
	This must be the first command after the connect.
	Supply your e-mail userid (this may or may not not the full e-mail address).
	Example: USER john.smith
	*/
	const string User(const string userId);

	/* PASS password
	This must be the next command after USER.
	Supply your e-mail password.
	The password may be case sensitive.
	*/
	const string PASS(const string password);

	/* STAT SPEC
	STAT The response to this is: +OK #msgs #bytes Where #msgs is the number of messages
	in the mail box and #bytes is the total bytes used by all messages.
	Sample response: +OK 3 345910
	*/
	const string STAT();

	/* LIST SPEC
	LIST The response to this lists a line for each message with its
	number and size in bytes, ending with a period on a line by itself. Sample response:
	+OK 3 messages
	1 1205
	2 305
	3 344400
	*/
	const string LIST();

	/* RETR SPEC
	This sends message number msg# to you (displays on the Telnet screen).
	You probably don't want to do this in Telnet (unless you have turned on Telnet logging).
	Example: RETR 2 */
	const string RETR(int msgNumber);

	/* DELE msg# SPEC
	This marks message number msg# for deletion from the server.
	This is the way to get rid a problem causing message.
	It is not actually deleted until the QUIT command is issued.
	If you lose the connection to the mail server before issuing the QUIT command,
	the server should not delete any messages. Example: DELE 3 */
	const string DELE(int msgNumber);

	/* RSET SPEC
	This resets (unmarks) any messages previously marked for deletion in this session
	so that the QUIT command will not delete them.
	*/
	const string RSET();

	/* QUIT SPEC
	This deletes any messages marked for deletion,
	and then logs you off of the mail server.
	This is the last command to use.
	This does not disconnect you from the ISP, just the mailbox.
	*/
	const string QUIT();

};
#endif