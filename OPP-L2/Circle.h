/**************************************************************\
*                                                              *
* Student: Chad Medeiros - 065 937 146                         *
* Name	  : Circle.h                                           *
* Purpose :                                                    *
*  Defines circle inherited class.                             *
*							                                   *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 25 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/

#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "Shape.h"

class Circle : public Shape
{
	double radius;

public:
	const double PI = 3.1415;

	Circle(double r) : Shape("Circle")	{ radius = r; }

	double getRadius()		{ return radius; }
	double getArea()		{ return PI * pow(radius, 2); }
	double getPerimeter()	{ return 2 * PI * radius; }

};
#endif
