#pragma once
#include"Account.h"

class NormalAccount : public Account
{
private : 

	double _bInterest;

public:

	NormalAccount(const std::string& accid = "default", const std::string& userid = "default", const double balance = 0,const double& irate=0.02):
		Account(accid,userid,balance), _bInterest(irate)
	{}

	const double& getRate() const
	{
		return _bInterest;
	}

	virtual void  Deposit(const double& money)
	{
		Account::Deposit(money);
		Account::Deposit(money* _bInterest);
	}

};

