/*
20/08/26

Toy_Project - Bankaccount management project

-version 0.3

==>main point is 

Inheritance
&& base class pointer can have derived class address && why virtual function is needed
*/

#include"AccountHandler.h"
#include"SYSYEM_MENU.h"
#include<limits>

int main()
{
	using namespace std;
	
	AccountHandler manager;
	
	while (true)
	{
		manager.ShowMenu();
		int inumber; //input number
		std::cout << "INPUT: ";
		cin >> inumber;

		//Exception
		if (cin.fail() || inumber < 1 || inumber>5)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Wrong input please try again" << endl;
		}
		if (inumber == 5)
		{
			cout << "Thank you goodbye, Exit the programming" << endl;
			break;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer enter

		//Start Menu switch
		switch (static_cast<MENU>(inumber))
		{
		case MENU::MEMU_MAKE :
			cout << endl;
			manager.MakeAccount();
			break;

		case MENU::MEMU_DEPOSIT:
			manager.DepositMoney();

			break;

		case MENU::MEMU_WITHDRAWAL:

			manager.WithdrawMoney();
			break;

		case MENU::MEMU_SHOWINFO:
			
			manager.ShowAllInfo();
			break;

		}//end switch

	}//end whiel



	return 0;
}

