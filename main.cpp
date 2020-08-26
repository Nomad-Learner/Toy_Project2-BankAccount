#include"Account.h"
#include"SYSYEM_MENU.h"
#include<limits>



//std::getline(std::cin, accid);


int main()
{
	std::string accid;
	using namespace std;
	const int MAX_NUMBER = 100;
	int accNum = 0;
	Account* Acoount_Arr[MAX_NUMBER]{ nullptr }; //initialize nullptr
	Account Acc; //make object to use member function
	
	while (true)
	{
		Account::ShowMenu();
		int inumber; //input number
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
			Acoount_Arr[accNum++] = Acc.MakeAccount();
			break;

		case MENU::MEMU_DEPOSIT:
			cout << "Write your account id";
			std::getline(std::cin, accid);
			for (int i = 0; i < MAX_NUMBER; i++)
		{
			if (Acoount_Arr[i] != nullptr)
				{
					if (Acoount_Arr[i]->getUserID() == accid)
				{
						Acoount_Arr[i]->DepositMoney();			
				}
				else
					cout << "Invalid Account id" << endl;
				}
		}

			break;

		case MENU::MEMU_WITHDRAWAL:

			cout << "Write your account id:  ";
			std::getline(std::cin, accid);
			for (int i = 0; i < MAX_NUMBER; i++)
			{
				if (Acoount_Arr[i] != nullptr)
				{
					if (Acoount_Arr[i]->getUserID() == accid)
					{
						Acoount_Arr[i]->WithdrawMoney();
					}
					else
						cout << "Invalid Account id" << endl;
				}
			}

			break;

		case MENU::MEMU_SHOWINFO:
			
			for (int i = 0; i < MAX_NUMBER; i++)
			{
				if(Acoount_Arr[i]!=nullptr)
				Acoount_Arr[i]->ShowAllInfo();
			}

			break;
		}



	}



	return 0;
}

