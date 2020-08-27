#pragma once
#include"Account.h"

class HIGHCreditAccount : public Account
{
private:

	double _bInterest; //basic Interest
	double _Credit_Interest;
	
public:
	HIGHCreditAccount(const std::string& accid = "default", const std::string& userid = "default", const double& balance = 0, const double& irate = 0.02,
		const double& credit_interest = 0.07):
		Account(accid,userid,balance), _bInterest(irate), _Credit_Interest(credit_interest)
	{}

	virtual void  Deposit(const double& money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (_bInterest+_Credit_Interest) );
	}
	

};

