#include "Pop3Adaptor.h"
#include <iostream>
#include <string>
#include <fstream>
#include "MailMessage.h"
#include "DateTime.h"
#include "Acount.h"
using namespace std;



Pop3Adaptor::Pop3Adaptor(const string& fileName)
{
	ifstream myfile;
	char word[250];
	char *part = new char[250];
	int counter = 0,size;
	char* id = new char[250];
	char* from = new char[250];
	char* to = new char[250];
	char* mailtime= new char[16];
	char* data=new char[250];
	int count2 = 0;
	myfile.open("Example.txt");
	if (myfile)
	{
		while (myfile.getline(word, 250))
		{

			myfile.getline(word, 250);
			if (word[0] != '#')
			{
				part = strtok(word, ",");
				while (part != NULL)
				{
					counter++;
					if (counter == 1)
					{
						_acount.setName(part);
					}
					if (counter == 2)
					{
						_acount.setPass(part);
					}
					if (counter == 3)
					{
						strcpy(id,part);
					}
					if (counter == 4)
					{
						strcpy(from, part);
					}
					if (counter == 5)
					{
						strcpy(to, part);
					}
					if (counter == 6)
					{
						strcpy(mailtime, part);
					}
					if (counter == 7)
					{
						
						size=strlen(part);
						strcpy(data, part);
						MailMessage Mail(id, from, to, mailtime, data, size);
						_acount.addMail(Mail);
						count2++;
						counter = 2;
					}
					part = strtok(NULL, ",");
					
				}
				
			}
			
		}
		myfile.getline(word, 250);
	}
	else
	{
		cout << "Unable to open file";
	}
	
}


Pop3Adaptor& Pop3Adaptor:: operator=(const Pop3Adaptor& server)
{
	
		_acount = server._acount;
		_user = server._user;
		_pass = server._pass;
		_connected = server._connected;
	
	return *this;
}
const string Pop3Adaptor::User(const string userId)
{
	if (userId == _acount.getUser())
	{
		_user = true;
		      if (_pass)
		       {
				  _connected = true;
		       }
			  return "+OK";
	}
	return "-ERR";
}

const string Pop3Adaptor::PASS(const string password)
{
	if (password == _acount.getPass())
	{
		_pass = true;
		if (_user)
		{
			_connected = true;
		}
		return "+OK";
	}
	return "-ERR";
}

const string Pop3Adaptor::STAT()
{
	
	string msgcoun = to_string(_acount.getMsgCount());
	
	string totalsize = to_string(_acount.getTotalSize());

	if (_connected)
	{
		return ("+OK " + msgcoun + "  " + totalsize + "\n");
	}
	else
		return "-ERR\n";
}

const string Pop3Adaptor:: LIST()
{
	if (_connected)
	{

		string temp;
		temp += "+OK " + to_string(_acount.getMsgCount());
		temp += " messages (" + to_string(_acount.getTotalSize()) + " bytes)\n";
		int max = _acount.getMsgCount();
		for (int i = 1; i <= max; i++)
		{
			MailMessage *mail = _acount.findMail(i);
			if (mail && !(mail->getDeleteFlag()))
				temp += to_string(i) + " " + to_string(mail->getSize()) + "\n";
		}
		temp += ".\n";
		return temp;
	}
	else
		return "-ERR\n";
}

const string Pop3Adaptor::RETR(int msgNumber)
{
	if (_connected)
	{
		if (msgNumber != 0)
		{
			MailMessage *mail = _acount.findMail(msgNumber);
			if (mail && !(mail->getDeleteFlag()))
			{
				string temp;
				temp += "+OK " + to_string(mail->getSize()) + " bytes\n";
				temp += "From: " + (string)(mail->getFrom()) + "\n";
				DateTime dtemp = mail->getMailTime();
				
				temp += "Date: " + dtemp.getDay() + "/" + dtemp.getMonth() + "/" + dtemp.getYear() + "\n";
				temp += "Time: " + dtemp.getHour() + ":" + dtemp.getMin() + ":" + dtemp.getSec() + "\n";
				temp += mail->getData() + "\n.\n";
				return temp;
			}
		}
	}
	return "-ERR\n";
}

const string Pop3Adaptor::DELE(int msgNumber)
{
	if (_connected)
	{
		if (msgNumber)
		{
			MailMessage *mail = _acount.findMail(msgNumber);
			if (mail)
			{
				mail->markForDeletion();
				return "+OK\n";
			}
		}
	}
	return "-ERR\n";
}

const string Pop3Adaptor::RSET()
{
	if (_connected)
	{
		int count = _acount.getMsgCount();
		for (int i = 1; i <= count; i++)
		{
			MailMessage *mail = _acount.findMail(i);
			if (mail)
				mail->unMarkDeletion();
		}
		return "+OK\n";
	}
	else
		return "-ERR\n";
}


const string Pop3Adaptor:: QUIT()
{
	if (_connected)
	{
		int count = _acount.getMsgCount();
		for (int i = 1; i <= count; i++)
		{
			MailMessage *mail = _acount.findMail(i);
			if (mail && mail->getDeleteFlag())
				_acount.removeMail(i);
		}
		_user = false;
		_pass = false;
		_connected = false;
		return "+OK diconnected from server.\n";
	}
	else
		return "-ERR\n";
}