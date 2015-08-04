/**************************************************************\
*                                                              *
* Student: Chad Medeiros - 065 937 146                         *
* Name	  : Rectangle.h                                        *
* Purpose :                                                    *
*  Defines rectangle inherited class.                          *
*							                                   *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 25 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
	double length;
	double width;

public:
	Rectangle(double l, double w) : Shape("Rectangle")
	{
		length = l;
		width = w;
	}

	double getArea()		{ return length*width; }
	double getPerimeter()	{ return 2 * length + 2 * width; }

protected:
	Rectangle(double l) : Shape("Square")
	{
		length = l;
	}
	
};
#endif
