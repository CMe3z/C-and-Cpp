/**************************************************************\
* Name	 : Acc.h                                               *
* Purpose:                                                     *
*  Defines 'Account' abstract base class                       *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 15 : Created - Chad Medeiros                     *
\**************************************************************/

#ifndef ACC_H
#define ACC_H

using namespace std;

class Account			
{
public:

	Account(char *_type, char *_szFName, char *_szLName, char *_szSIN, double _dBalance)
	{
		accType = string(_type);
		fName = string(_szFName);
		lName = string(_szLName);
		SIN = string(_szSIN);
		curBal = _dBalance;
	};

	virtual ~Account() {};

	string getFName()	{ return fName; }
	string getLName()	{ return lName; }
	string getAccType()	{ return accType; }
	string getSIN()		{ return SIN; }
	double getBalance()	{ return curBal; }
	int getTotalTransactions() { return (depCount + withCount); }

	virtual void Deposit(double* _changeBal, unsigned int* _transCount) = 0;
	virtual void Withdraw(double* _changeBal, unsigned int* _transCount) = 0;

private:

	string fName;
	string lName;
	string SIN;
	string accType;

protected:

	double curBal;
	int depCount = 0;
	int withCount = 0;

};
