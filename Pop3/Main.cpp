#include "MailInterface.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])	
{
	
	if (argc != 2)
	{
		cout << "Input Error.\n";
		return 1;
	}
	MailInterface user(argv[1]);		
	user.screenMenu();                 
	system("Pause");
	return 0;
}
