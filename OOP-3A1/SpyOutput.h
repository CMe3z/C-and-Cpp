/**************************************************************\
*                                                              *
* Name	  : SpyOutput.h                                        *
* Purpose :                                                    *
*  Defines the SpyOutput Class, the << operator for it, and    *
*  the getCount and getChecksum functions to retrieve their    *
*  respective values.                                          *
*							                                   *
****************************************************************
* MODIFICATION HISTORY :                                       *
* 2015 - 09 - 24 : Created - Chad Medeiros                     *
*                                                              *
\**************************************************************/

#ifndef SPYOUTPUT_H
#define SPYOUTPUT_H

#include <strstream>
#include <sstream>

using namespace std;

class SpyOutput
{
	ostream * out;
	int count, checksum;

public:
	SpyOutput(ostream * _cout)
	{
		out = _cout;
		count = 0;
		checksum = 0;
	}

	template <class T>
	SpyOutput &operator <<(const T &in)
	{
		*out << in;

		stringstream ss;	// Send 'in' into stringstream so we can convert to ASCII  
		ss << in;			// and then get character data (count, checksum)
		string s;
		s = ss.str();

		count += s.size();	// Calculate character count

		for (int i = 0; i < s.size(); i++) checksum += s[i]; // Calculate checksum value.

		return *this;
	}

	int getCount()		{ return count; }
	int getCheckSum()	{ return checksum; }

};
#endif