/**************************************************************\
* Name	 : Main.cpp                                            *
* Purpose:                                                     *
*  Provided by Assignment. Objective is to write header files  *
*  which will make this code fully functional.                 *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 15 : Copied from Assignment - Chad Medeiros      *
\**************************************************************/

#include <iostream>
#include <string>
#include "Acc.h"
#include "Saving.h"
#include "Checking.h"
#include "VIP.h"

using namespace std;

void AccStatement(Account *acc);
void Transaction(Account *acc);

#define MAX_ACCOUNTS 3
#define MAX_TRANSACTIONS 5

int main()
{
	char szFName[32];
	char szLName[32];
	char szSIN[12];
	char szAccType[10];
	double dBalance;
	int op;
	Account *acc[MAX_ACCOUNTS];
	int count = 0;
	while (count<MAX_ACCOUNTS)
	{
		cout << "Customer's First Name : " << flush;
		cin >> szFName;
		cout << "Customer's Last Name : " << flush;
		cin >> szLName;
		cout << "Customer's SIN : " << flush;
		cin >> szSIN;
		cout << "Account Type : " << flush;
		cin >> szAccType;
		cout << "Opening Balance : " << flush;
		cin >> dBalance;

		if (!strcmp(szAccType, "Checking"))
			acc[count] = new CheckingAcc(szFName, szLName, szSIN, dBalance);
		else if (!strcmp(szAccType, "VIP"))
			acc[count] = new VIPAcc(szFName, szLName, szSIN, dBalance);
		else if (!strcmp(szAccType, "Saving"))
			acc[count] = new SavingAcc(szFName, szLName, szSIN, dBalance);
		else
		{
			cout << "Incorect account type." << endl;
			continue;
		}
		count++;
	}

	for (count = 0; count<MAX_ACCOUNTS; count++)
	{
		cout << acc[count]->getAccType().data() << " account. Owner: "
			<< acc[count]->getFName().data() << " "
			<< acc[count]->getLName().data() << endl;
		for (op = 0; op<MAX_TRANSACTIONS; op++)
		{
			Transaction(acc[count]);
		}
	}

	// Display the balance
	for (count = 0; count<MAX_ACCOUNTS; count++)
		AccStatement(acc[count]);

	for (count = 0; count<MAX_ACCOUNTS; count++)
		delete acc[count];
	return (0);
}


void Transaction(Account *acc)
{
	char chTran;
	double dBalance;
	unsigned int nCount;

	cout << "Enter amount : " << flush;
	cin >> dBalance;
	cout << "Deposit (d), Withdraw (w):" << flush;
	cin >> chTran;
	if (chTran == 'd' || chTran == 'D')
	{
		acc->Deposit(&dBalance, &nCount);
	}
	else if (chTran == 'w' || chTran == 'W')
	{
		acc->Withdraw(&dBalance, &nCount);
	}
	cout << "Balance = " << dBalance
		<< "  Total Transactions = " << nCount << endl;
}


void AccStatement(Account *acc)
{
	cout << "Customer: " << acc->getFName().data() << " " << acc->getLName().data() << endl;
	cout << "Accunt type: " << acc->getAccType().data() << endl;
	cout << "Present Balance: " << acc->getBalance() << endl;
	cout << "Total Transactions: " << acc->getTotalTransactions() << endl;
	cout << endl;
}
