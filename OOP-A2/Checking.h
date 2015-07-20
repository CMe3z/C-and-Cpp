/**************************************************************\
* Name	 : Checking.h                                          *
* Purpose:                                                     *
*  Defines 'CheckingAcc' concrete class.                       *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 15 : Created - Chad Medeiros                     *
\**************************************************************/

#ifndef CHECKING_H
#define CHECKING_H

using namespace std;

class CheckingAcc : public Account
{
public:

	CheckingAcc(char *_szFName, char *_szLName, char *_szSIN, double _dBalance) :
		Account("Checking", _szFName, _szLName, _szSIN, _dBalance) {};

	void Deposit(double* _changeBal, unsigned int* _transCount)
	{
		++depCount;									// Add +1 to counter for number of deposits made.
		*_transCount = (depCount + withCount);		// Return the total number of transactions performed.
		curBal += *_changeBal;						// Add deposit amount to current balance.
		
		if ((depCount % 4) == 0) 
		{
			curBal += 2;							// Every fourth deposit, add $2 to account.
		}

		*_changeBal = curBal;						// Return current balance.
	}

	void Withdraw(double* _changeBal, unsigned int* _transCount)
	{
		++withCount;								// Add +1 to counter for number of withdrawls made.
		*_transCount = depCount + withCount;		// Return the total number of transactions performed.	
		curBal -= *_changeBal;						// Subtract withdraw amount from current balance.

		if ((withCount % 4) == 0) 
		{
			curBal -= 3;							// Every fourth withdrawl, deduct $3 from account.
		}		

		if (curBal < 4000)
		{
			curBal -= 5;							// After withdrawl & deductions, if balance is less 
		}											// than $4,000, deduct $5 from account
		
		*_changeBal = curBal;						// Return current balance.

	}

	~CheckingAcc() {};

};
#endif
