/**************************************************************\
*                                                              *
* Name	  : SalaryMain.cpp                                     *
* Purpose :                                                    *
* Defines Employee structure to hold basic employee info and   *
*  salary information. Also creates Functor to handle and      *
*  simplify code in SalaryMain.cpp's count_if() calls.         *
*							                                   *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 11 - 01 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/


#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Salary.h"

using namespace std;

#define NUM_EMP 15

int main() {

	// Temporary list of names to feed into the Employee vector later:
	char * tempnames[30] = { "Bob", "Brown", "Sandra", "Stalwart", "Sally", "Roberts", "Gary", "Brooks", "Bobby", "Brown", "Ming", "Chan", "Bryant", "Smith", "Ahmed", "Abdeel", "Michael", "Jutzi", "Nicki", "Menauge", "Tom", "Riddle", "Robert", "Faulcner", "Nicole", "Smith", "Stewart", "Peterson", "Alison", "McDowell"};
	
	vector<Employee> employees;
	employees.resize(NUM_EMP);

	// Create heading for employee list:
	cout << "EMPLOYEE SALES AND SALARY" << endl;
	cout << setw(12) << "First Name" << setw(11) << "Last Name" << setw(9) << "Sales" << setw(10) << "Base Pay" << setw(9) << "Bonus" << setw(14) << "Total Salary" << endl;
	
	// Input employee info and display the list:
	for (int i = 0; i < NUM_EMP; i++)
	{
		employees[i].fname = tempnames[2*i];		// Copy names into employee objects (can be done many ways, this seemed shortest)
		employees[i].lname = tempnames[2*i+1];

		employees[i].sales = (500 + 610 * i);		// Input a range of sales values
		employees[i].bonus = employees[i].sales*0.09;	// Calculate commission bonus (9% of sales)
		
		// List all employees
		cout << fixed << setprecision(2) << setw(12) << employees[i].fname << setw(11) << employees[i].lname << setw(9) << employees[i].sales << setw(10) << employees[i].income << setw(9) << employees[i].bonus << setw(14) << employees[i].bonus + employees[i].income << endl;
	}

	// Salary Breakdown:
	cout << endl << left << "SALARY BREAKDOWN" << endl;
	cout << setw(14) << "Salary Range" << setw(16) << "# of Employees" << endl;
	for (int i = 2; i < 10; i++) {
		cout << right << setw(5) << "$"<< i << "00-" << i << "99" << setw(3) << count_if(employees.begin(), employees.end(), Between(i*100, (i*100)+99)) << endl;	
	}
	cout << right << setw(12) << "$1000+" << setw(3) << count_if(employees.begin(), employees.end(), GreaterThan1000) << endl;

	system("pause");
	return 0;
}