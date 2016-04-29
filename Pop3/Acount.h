#ifndef _ACOUNT_H
#define _ACOUNT_H

#include <String.h>
#include "MailMessage.h"
#include "MyList.h"

class Acount
{
	private :
		string _name;					//email
		string _pass;					//password
		int _msgCount;					//how many mails
		int _size;						//how much they weigh
		MyList<MailMessage> _mailBox;	//and where they at
	public:
		Acount(){ _size = 0; _msgCount = 0; }  
		Acount(const Acount &acount);    //copy constractor
		Acount& operator=(const Acount& ac);
		//setters
		void setName(char* name);
		void setPass(char* pass);
		void setMsgCount(int num);
		void setSize(int num);
		//getters
		const string&	getUser();
		const string&	getPass();
		 int		getMsgCount();
		 int		getTotalSize();
		void addMail(const MailMessage& mail);											//insert a mail to the list
		bool removeMail(const int& index);												//remove mail at index
		MailMessage* findMail(const int& index);	                                    //return pointer to mail at index

};

#endif