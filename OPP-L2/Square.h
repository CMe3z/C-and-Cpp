/**************************************************************\
*                                                              *
* Student: Chad Medeiros                                       *
* Name	  : Square.h                                           *
* Purpose :                                                    *
*  Defines square inherited class.                             *
*							                                                 *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 07 - 25 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/

#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

class Square : public Rectangle 
{
	double length;
public:
	
	Square(double l) : Rectangle(l)
	{
		length = l;
	}

	double getArea()	{ return length * length ; }
	double getPerimeter()	{ return 4 * length; }
};
#endif
