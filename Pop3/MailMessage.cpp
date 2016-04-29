#include "MailMessage.h"
#include <iostream>
#include <string>
#include "DateTime.h"
using namespace std;



MailMessage::MailMessage()
{
	_size = 0;
	_id = '0';
	_from = '0';
	_deletemailFlag = true;
	_to = '0';
	_mailTime="00000000000000";
	_data = '0';
}

MailMessage::MailMessage(char* id,char* from,char* to,char* mailtime,char* data,int size)
: _deletemailFlag(false), _mailTime(mailtime)
{
	
	 _id=id;
	 _from=from;
	 _to=to;
	 _data=data;
	 _size = size;

}
MailMessage::MailMessage(const MailMessage &mailmessage)
{
	_deletemailFlag = mailmessage._deletemailFlag;
	_size = mailmessage._size;
	_id = mailmessage._id;
	_from = mailmessage._from;
	_to = mailmessage._to;
	_mailTime = mailmessage._mailTime;
	_data = mailmessage._data;
	
}

MailMessage& MailMessage :: operator=(const MailMessage &msg)
{
	_deletemailFlag=msg._deletemailFlag;	     
	_size=msg._size;        
	_id=msg._id;
	_from=msg._from;
	_to=msg._to;
    _mailTime=msg._mailTime;
	_data=msg._data;
	return *this;
}

const string&	MailMessage::getID()
{
	return _id;
}
const string&	MailMessage::getFrom()
{
	return _from;
}
const string&	MailMessage::getTo()
{
	return _to;
}
const DateTime&	MailMessage::getMailTime()
{
	return _mailTime;
}
const string&	MailMessage::getData()
{
	return _data;
}
const int&  MailMessage::getSize() const
{
	return _size;
}

bool MailMessage::getDeleteFlag()
{
	return _deletemailFlag;
}


void MailMessage::markForDeletion()
{
	_deletemailFlag = true;
}
void MailMessage:: unMarkDeletion()
{
	_deletemailFlag = false;
}
