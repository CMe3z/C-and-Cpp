/**************************************************************\
* Name	 : Saving.h                                            *
* Purpose:                                                     *
*  Defines 'SavingAcc' concrete class.                         *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 15 : Created - Chad Medeiros                     *
\**************************************************************/

#ifndef SAVING_H
#define SAVING_H

using namespace std;

class SavingAcc : public Account 
{
public:

	SavingAcc(char *_szFName, char *_szLName, char *_szSIN, double _dBalance) :
			Account("Saving", _szFName, _szLName, _szSIN, _dBalance) {};
	
	void Deposit(double* _changeBal, unsigned int* _transCount) 
	{
		++depCount;									// Add +1 to counter for number of deposits made.
		*_transCount = (depCount + withCount);		// Return the total number of transactions performed.
		curBal += *_changeBal;						// Add deposit amount to current balance.

		if ((depCount % 3) == 0) 
		{
			curBal -= 1;							// Every third deposit, deduct $1 from account.
		}

		*_changeBal = curBal;						// Return current balance.
	}

	void Withdraw(double* _changeBal, unsigned int* _transCount) 
	{
		++withCount;								// Add +1 to counter for number of withdrawls made.
		*_transCount = depCount + withCount;		// Return the total number of transactions performed.
		curBal -= *_changeBal;						// Subtract withdraw amount from current balance.
		
		if ((withCount % 3) == 0) 
		{
			curBal -= 2;							// Every third withdrawl, deduct $2 from account.
		}
		
		*_changeBal = curBal;						// Return current balance.
	}
	
	~SavingAcc() {};

};
#endif
