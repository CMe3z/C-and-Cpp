/**************************************************************\
*                                                              *
* Student: Chad Medeiros                                       *
* Name	  : ShapeMain.cpp                                      *
* Purpose :                                                    *
*  Creates an array of shapes & outputs their details          *
*							                                                 *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 25 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include <iostream>

using namespace std;

int main()
{
	Shape *shape[3];

	shape[0] = new Circle(10);
	shape[1] = new Rectangle(10, 11);
	shape[2] = new Square(5);

	for (int i = 0; i <= 2; i++)
	{
		cout << *shape[i] << endl;
	}
	
	delete [] shape;
	return 0;
}
