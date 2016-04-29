#ifndef _MAILMESSAGE_H
#define _MAILMESSAGE_H
#include <iostream> 
#include <string>
#include "DateTime.h"

using namespace std;

class MailMessage
{
public:
	MailMessage();
	MailMessage(char* id, char* from, char* to,char* mailtime, char* data, int size); //Conversion Constructor,I need it because I take the informtion from file
	MailMessage(const MailMessage &mailmessage);   //copy Ctor

	MailMessage& operator=(const MailMessage &msg); //operator =

	const string&	getID();
	const string&	getFrom();
	const string&	getTo();
	const DateTime&	getMailTime();
	const string&	getData();
    const int&  getSize() const ;
	bool getDeleteFlag();

	void markForDeletion();           //Deletion
	void unMarkDeletion();
	

private:
	bool _deletemailFlag;	         //Marks the mail for deletion at Quit	
	int _size;        //I can't understand from the instruction of the exc' if it is the size of all the detail of the mail or only the size of the content of the message so I decide refer to the content for exampe if the content of the message is "tavor" the size is 5
	string _id;
	string _from;
	string _to;
	DateTime _mailTime;
	string _data;
	

};
#endif
