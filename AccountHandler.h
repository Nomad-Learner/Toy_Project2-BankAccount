#pragma once

/*

Contrpl Class

have funciotn

*/

#include"CHOICE.h"
#include<string>
#include<iostream>
#include<limits>
#include "Account.h"
class AccountHandler
{
private:
	static const int MAX_NUMBER = 100;
	int _accNum ;
	Account* _Acoount_Arr[MAX_NUMBER];

public:
	
	AccountHandler() : _accNum(0)
	{
		for (int i = 0; i < MAX_NUMBER; i++)
		{
			_Acoount_Arr[i] = nullptr;

		}
	}

	~AccountHandler()
		{
			for(int i=0;i< _accNum;i++)
			delete _Acoount_Arr[i];
			std::cout << "AccountHandler destructor" << std::endl;
		}

	void ShowAllInfo() const
	{
		for (int i = 0; i < MAX_NUMBER; i++)
		{
			if (_Acoount_Arr[i] != nullptr)
			{
				_Acoount_Arr[i]->ShowAllInfo();

			}

		}
	}

	void ShowMenu()
	{
		std::cout << "==================Menu======================" << std::endl;
		std::cout << "1.Making account" << std::endl;
		std::cout << "2.Deposit" << std::endl;
		std::cout << "3.Withdrawal" << std::endl;
		std::cout << "4.Show account info" << std::endl;
		std::cout << "5.Exit acoount program" << std::endl;

	}

		void MakeAccount()
		{
			std::string accid;
			std::string userid;
			double money;
			int inumber;//input number
			int count = 0;
			std::cout << "=================Making account=======================" << std::endl;
			std::cout << "if you want to go back please write number 2 or make account please write number 1" << std::endl;
			while (true)
			{
				std::cin >> inumber;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					count++;
					std::cout << "Error count: " << count << std::endl;
					if (count == 3)
					{
						std::cout << "Too many Wrong input go back to Menu" << std::endl;

					}

				}
				else
					break;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (static_cast<CHOICE>(inumber))
			{
			case CHOICE::CHOICE_GO:

				std::cout << "Write your accountid: ";
				std::getline(std::cin, accid);
				std::cout << "Write your userid: ";
				std::getline(std::cin, userid);
				std::cout << "Money you want to deposit: ";
				while (true)
				{
					std::cin >> money;
					if (std::cin.fail() || money < 0)
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Wrong moeny Please try again" << std::endl;

					}
					else
						break;
				}
				_Acoount_Arr[_accNum++]= new Account(accid, userid, money);

			case CHOICE::CHOICE_BACK:

				break;

			default:
				break;
			}//end case
		}//end MakeAccount function

		void DepositMoney()
		{
			std::string inputID;
			double money;
			int count = 0;
			std::cout << "Write your account id ";
			std::getline(std::cin, inputID);
				for (int i = 0; i < MAX_NUMBER; i++)
				{
					if (_Acoount_Arr[i]->getAccID() == inputID)
					{
						std::cout << "How much money do you want deposit ?";
						//exception
						while (true)
						{
							std::cin >> money;
							if (std::cin.fail() || money < 0)
							{
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cout << "Wrong moeny Please try again" << std::endl;
								count++;
								std::cout << "Error count: " << count << std::endl;
								if (count == 3)
								{
									std::cout << "Too many Wrong input go back to Menu" << std::endl;
									return;
								}
							}
							else
								break;
						}//while end
						_Acoount_Arr[i]->Deposit(money);
						std::cout << "Deposit Done!" << std::endl;
						break;
					}//end if
				
				}//end for
				
		}//end function

		void WithdrawMoney()
		{
			std::string inputID;
			double money;
			int count = 0;
			std::cout << "Write your account id ";
			std::getline(std::cin, inputID);
			for (int i = 0; i < MAX_NUMBER; i++)
			{
				if (_Acoount_Arr[i]->getAccID() == inputID)
				{
					std::cout << "How much money do you want withdraw? ";
					while (true)
					{
						std::cin >> money;
						//exception
						if (std::cin.fail() || (_Acoount_Arr[i]->getBalance() - money < 0))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "Wrong moeny Please try again" << std::endl;
							count++;
							std::cout << "Error count: " << count << std::endl;
							if (count == 3)
							{
								std::cout << "Too many Wrong input go back to Menu" << std::endl;
								return;
							}
						}
						else
							break;
					}//end while
					_Acoount_Arr[i]->Withdrawal(money);
					std::cout << "Withdraw Done!" << std::endl;
					break; //break for
				}//end if
				
			}//end for
		}//end function






};

