/**************************************************************\
*                                                              *
* Name	  : SpyOutputMain.cpp                                  *
* Purpose :                                                    *
*  Utilize a developed class that behaves like cout, but will  *
*  count the total number of ASCII characters inputted, as     *
*  well as calculate the checksum value of the entire string.  *
*							                                   *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 09 - 24 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/

#include <iostream>
#include "SpyOutput.h"

using namespace std;

#define endl '\n'

void main()
{
	double d1 = 123.4;
	int i1 = 456;

	SpyOutput spy(&cout);

	spy << "d1=" << d1 << " i1=" << i1 << 'W' << endl;
	spy << "abcdef" << endl;

	cout << "Count=" << spy.getCount() << endl;
	cout << "Check Sum=" << spy.getCheckSum() << endl;
}