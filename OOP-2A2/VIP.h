/**************************************************************\
* Name	 : VIP.h                                               *
* Purpose:                                                     *
*  Defines 'VIPAcc' concrete class.                            *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 15 : Created - Chad Medeiros                     *
\**************************************************************/
#ifndef VIP_H
#define VIP_H

using namespace std;

class VIPAcc : public Account
{
public:

	VIPAcc(char *_szFName, char *_szLName, char *_szSIN, double _dBalance) :
		Account("VIP", _szFName, _szLName, _szSIN, _dBalance) {};

	void Deposit(double* _changeBal, unsigned int* _transCount)
	{
		++depCount;									// Add +1 to counter for number of deposits made.
		*_transCount = (depCount + withCount);		// Return the total number of transactions performed.
		curBal += *_changeBal;						// Add deposit amount to current balance.

		if (*_changeBal > 10000)
		{
			curBal += 6;							// For every deposit over $10,000, add $6 to account.
		}

		*_changeBal = curBal;						// Return current balance.
	}

	void Withdraw(double* _changeBal, unsigned int* _transCount)
	{
		++withCount;								// Add +1 to counter for number of withdrawls made.
		*_transCount = depCount + withCount;		// Return the total number of transactions performed.
		curBal -= *_changeBal;						// Subtract withdraw amount from current balance.

		if ((withCount % 9) == 0)
		{
			curBal -= 4;							// Every ninth withdrawl, deduct $4 from account.
		}

		*_changeBal = curBal;						// Return current balance.

	}

	~VIPAcc() {};
};
#endif
