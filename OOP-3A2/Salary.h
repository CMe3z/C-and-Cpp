/**************************************************************\
*                                                              *
* Name	  : Salary.h                                           *
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

#ifndef SALARY_H
#define SALARY_H

struct Employee {

	char * fname;
	char * lname;
	double sales, bonus;
	double income = 200;

};


// Create a Functor for count_if()'s use in SalaryMain.cpp (as it is typically Unary):
class Between {
	const size_t min, max;

public:
	explicit Between(size_t iMin, size_t iMax) : min(iMin), max(iMax) {}

	bool operator() (Employee emp) const {
		return (trunc(emp.income + emp.bonus) >= min && trunc(emp.income + emp.bonus) <= max);
	}
};

// Typical condition for count_if(), no need for functor in this case:
bool GreaterThan1000(Employee emp) { return ((emp.income + emp.bonus) >= 1000); }

#endif