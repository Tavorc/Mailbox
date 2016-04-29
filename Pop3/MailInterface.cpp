#include "MailInterface.h"
#include "Pop3Adaptor.h"
#include <string>
#include <iostream>


using namespace std;

MailInterface :: MailInterface(const string& fileName)
: _server(fileName)
{}

bool MailInterface::authorization()
{
	string user, pass;
	int choice;
	while (true)
	{
	cout << "\n Menu:\n"
		<< "1. To log into the server press 1.\n"
		<< "2. To log out from  program press 2.\n"
		<< "Your decision is : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter Email: ";
			cin >> user;
			cout << "Enter Password: ";
			cin >> pass;
			if (_server.User(user) == "-ERR" ||
				_server.PASS(pass)=="-ERR")
				cout << "Your username or password is wrong.\n";
			else
			{
				cout << "Approved Login.\n";
				return true;
			}
			break;
		case 2:
			cout << "\nExiting the program, Goodbye!\n";
			return false;
		}
	}
}

void MailInterface::screenMenu()
{
	cout << "Welcome to Mailbox :\n";
	bool connected;
	while ((connected = authorization()))
	{
		while (connected)
		{
			cout << "\nMail Menu:\n"
				<< "1. Get Mail Status.\n"
				<< "2. Get Mail List.\n"
				<< "3. Get One Mail.\n"
				<< "4. Delete Mail.\n"
				<< "5. Reset.\n"
				<< "6. Quit.\n"
				<< "Enter choice : ";
			int ind;
			cin >>ind;
			switch (ind)
			{
			case 1:
				cout << endl << _server.STAT() << endl;
				break;
			case 2:
				cout << endl << _server.LIST() << endl;
				break;
			case 3:
				cout << "\nEnter number of messege: ";
				cin >> ind;
				cout << _server.RETR(ind) << endl;
				break;
			case 4:
				cout << "\nEnter number of messege: ";
				cin >> ind;
				cout << _server.DELE(ind) << endl;
				break;
			case 5:
				cout << endl << _server.RSET() << endl;
				break;
			case 6:
				cout << endl << _server.QUIT() << endl;
				connected = false;
				break;
			default:
				cout << "\nError: Wrong Input.\n\n";
			}
		}
	}
}
