#include "Acount.h"
#include <String.h>
#include "MailMessage.h"
#include "MyList.h"
#include <iostream>
#include <string>

using namespace std;


Acount :: Acount(const Acount &acount)
{
	 _name=acount._name;					
	 _pass = acount._pass;
	 _msgCount = acount._msgCount;
	 _size = acount._size;
	 _mailBox = acount._mailBox;
}

Acount& Acount:: operator=(const Acount& ac)
{
	_name = ac._name;
	_pass = ac._pass;
	_msgCount = ac._msgCount;
	_size = ac._size;
	_mailBox = ac._mailBox;
	return *this;
}

void Acount::setName(char* name)
{
	_name = name;
}
void Acount::setPass(char* pass)
{
	_pass = pass;
}
void Acount::setMsgCount(int num)
{
	_msgCount =num;
}
void Acount:: setSize(int num)
{
	_size=num;
}

const string&	Acount :: getUser()
{
	return _name;
}
const string&	Acount::getPass()
{
	return _pass;
}
 int		Acount::getMsgCount()
{
	return _msgCount;
}
 int		Acount::getTotalSize()
{
	return _size;
}

void  Acount::addMail(const MailMessage& mail)
{
	_mailBox.add(mail);
	_msgCount++;
	_size += mail.getSize();
}
bool Acount::removeMail(const int& index)
{
	MailMessage mail;
	bool remove = _mailBox.remove(index, mail);
	_size -= mail.getSize();
	if (remove)
		_msgCount--;
	return remove;
}
MailMessage* Acount::findMail(const int& index)
{
	return _mailBox.find(index);
}