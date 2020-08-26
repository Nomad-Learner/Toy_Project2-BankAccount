#pragma once

#include<string>
#include<iostream>
#include<limits>
class Account
{
private:

	std::string _AccountID;
	std::string _UserID;
	double _balance;

public:

	Account(const std::string& accid="default",const std::string& userid="default" , const double balance=0) : _AccountID(accid)
		,_UserID(userid)
		,_balance(balance)
	{}

	//use static function to use ShowMenu in Main without Account object
	static void ShowMenu() 
	{
		std::cout << "==================Menu======================" << std::endl;
		std::cout << "1.Making account" << std::endl;
		std::cout << "2.Deposit" << std::endl;
		std::cout << "3.Withdrawal" << std::endl;
		std::cout << "4.Show account info" << std::endl;
		std::cout << "5.Exit acoount program" << std::endl;

	}

	void ShowAllInfo() const
	{
		std::cout << "Account ID: " << _AccountID<<'\t' << "UserID: " << _UserID << '\t' << "Balance: " << _balance << std::endl;

	}
	
	Account* MakeAccount()
	{
		std::string accid;
		std::string userid;
		double money;
		std::cout << "===============Making account=======================" << std::endl;
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

		return new Account(accid, userid, money);
	}

	void DepositMoney()
	{
		double money;
		std::cout << "How much money do you want deposit?";
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
		_balance += money; 
		std::cout << "Done!" << std::endl;
	}


	void WithdrawMoney()
	{

		std::cout << "How much money do you want withdraw?";
		double money;
		while (true)
		{
			std::cin >> money;
			if (std::cin.fail() || (_balance-money<0) )
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong moeny Please try again" << std::endl;

			}
			else
				break;
		}

		_balance -= money;

	}

	const std::string getAccID() const
	{
		return _AccountID;
	}

	const std::string getUserID() const
	{
		return _UserID;
	}



};

