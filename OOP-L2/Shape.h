/**************************************************************\
*                                                              *
* Student: Chad Medeiros                                       *
* Name	  : Shape.h                                            *
* Purpose :                                                    *
*  Defines shape abstract class                                *
*							                                                 *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 25 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/

#ifndef SHAPE_H
#define SHAPE_H
#include <iomanip>

using namespace std;

class Shape
{
	char *name;
	
	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
	
	friend ostream & operator<< (ostream &os, Shape &sh) {
		os.setf(ios::left);
		os << setw(16) << sh.name
			<< setw(16) << sh.getPerimeter()
			<< setw(16) << sh.getArea();
		return os;
	}
public:

	Shape(char *n)
	{
		name = new char[];
		strcpy(name, n);
	}
			
};
#endif
