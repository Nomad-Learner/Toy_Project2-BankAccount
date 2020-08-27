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
#include"NormalAccount.h"
#include"HIGHCreditAccount.h"
#include"CREDIT_GRADE.h"
#include"InterestRate.h"

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
			int inumber;//input number
			int count = 0;
			std::cout << "========================Making account=======================" << std::endl;
			std::cout << "if you want to make NormalAccount input number 1, or if you want to make HighCreditAccount input number 2." << std::endl;
			while (true)
			{
				std::cin >> inumber;
				if (std::cin.fail()|| inumber<1||inumber>2) //exception
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore enter key
			switch (static_cast<CHOICE>(inumber))
			{
			case CHOICE::CHOICE_NORMALACCOUNT:
				//early reurn to check number of account
				if (_accNum >= MAX_NUMBER)
					return;

				MakeNormalAccount();
				break;

			case CHOICE::CHOICE_HIGHCREDITACCOUNT:
				//early reurn to check number of account
				if (_accNum >= MAX_NUMBER)
					return;
				MakeHighCreditAccount();

				break;

			default:
				break;
			}//end case
		}//end MakeAccount function

		void MakeNormalAccount()
		{
			std::cout << "=======================[Normal_Account]============================" << std::endl;
			std::string accid;
			std::string userid;
			double money;
			double irate; //interest rate
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
			
			std::cout << "Input basic interest rate ";
			while (true)
			{
				std::cin >> irate;
				if (std::cin.fail() || money < 0)
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Wrong interest rate Please try again" << std::endl;

				}
				else
					break;
			}
			_Acoount_Arr[_accNum++] = new NormalAccount(accid, userid, money,irate);//parent class pointer -> derived class 
		}//end MakeNormalAccount

		void MakeHighCreditAccount()
		{
			std::cout << "=======================[HighCredit_Account]============================" << std::endl;
			std::string accid;
			std::string userid;
			double money;
			double irate; //interest rate
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

			std::cout << "Input basic interest_rate: ";
			while (true)
			{
				std::cin >> irate;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Wrong interest rate Please try again" << std::endl;

				}
				else
					break;
			}

			int igrade; //input grade
			double cgrade=0; //credit grade
			std::cout << "Credit Grade(1toA, 2toB, 3toC): ";
			while (true)
			{
				std::cin >> igrade;
				if (std::cin.fail() || igrade < 1 || igrade > 3 )
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Wrong credit grade Please try again" << std::endl;

				}
				else
					break;
			}
			switch (static_cast<CREDIT_GRADE>(igrade))
			{
			case CREDIT_GRADE::CREDIT_A :

				cgrade = InterestRate::Credit_A;

				break; 

			case CREDIT_GRADE::CREDIT_B:

				cgrade = InterestRate::Credit_B;
				break;


			case CREDIT_GRADE::CREDIT_C:

				cgrade = InterestRate::Credit_C;
				break;

			}
			_Acoount_Arr[_accNum++] = new HIGHCreditAccount(accid, userid, money, irate, cgrade);//parent class pointer -> derived class 

		}//end MakeHighCreditAccount

		void DepositMoney()
		{
			std::string inputID;
			double money;
			int count = 0;
			std::cout << "Write your account id ";
			std::getline(std::cin, inputID);
				for (int i = 0; i < _accNum; i++)
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
						return; //return exit for
					}//end if
				
				}//end for
				std::cout << "Wrong account ID" << std::endl;
		}//end function

		void WithdrawMoney()
		{
			std::string inputID;
			double money;
			int count = 0;
			std::cout << "Write your account id ";
			std::getline(std::cin, inputID);
			for (int i = 0; i < _accNum; i++)
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
							std::cout << "Your balance is: " << _Acoount_Arr[i]->getBalance() << std::endl;
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
					return; //return exit for
				}//end if

			}//end for
			std::cout << "Wrong account ID" << std::endl;
		}//end function


};

