#pragma once

#include"CHOICE.h"
#include"BoundCheckArray.h"
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

	Account(const std::string& accid="default",const std::string& userid="default" , const double& balance=0) : _AccountID(accid)
		,_UserID(userid)
		,_balance(balance)
	{}

	void ShowAllInfo() const
	{
		std::cout << "Account ID: " << _AccountID<<'\t' << "UserID: " << _UserID << '\t' << "Balance: " << _balance << std::endl;

	}
	
	virtual void Deposit(const double& money)
	{
		_balance += money;
	}

	void Withdrawal(const double& money)
	{
		_balance -= money;
	}
	const double getBalance() const
	{
		return _balance;
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

