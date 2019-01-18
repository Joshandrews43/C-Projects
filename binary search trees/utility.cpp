//Authors: Madeleine Allen
//All class declarations go here


#include<iostream>
#include<string>
#include <stdio.h>
#include "utility.h"
using namespace std;

int cardStringToInt(string c)
{
	char suite = c[0];
	int val = atoi(c.substr(1, c.size()-1).c_str());
	if (val==0)	
	{
		char face = c[2];
		switch(face)
		{
			case 'a':val=1;
				break;
			case 'j':val=11;
				break;
			case 'q':val=12;
				break;
			case 'k':val=13;
				break;
		}
	
	}
	int multiplier = 0;
	switch(suite)
		{
			case 'c':multiplier=0;
				break;
			case 'd':multiplier=1;
				break;
			case 's':multiplier=2;
				break;
			case 'h':multiplier=3;
				break;
		}
//	printf("converted to %c %i %i\n",suite,val, multiplier*13+val);
	return multiplier*13+val;
}
string intToCardString(int c)
{
	int val = c%13;
	int q = (c-val)/13;//now q is 3
	char suite = 'v';
	if(val!=0)
	{
	switch(q)
		{

			case 0: suite='c';
				break;
			case 1: suite='d';
				break;
			case 2: suite='s';
				break;
			case 3: suite='h';
				break;
		}
	}
//
	else //for the case where the card is a king, this needs to be adjusted
	{

		switch(q)
                {

                        case 1: suite='c';
                                break;
                        case 2: suite='d';
                                break;
                        case 3: suite='s';
                                break;
                        case 4: suite='h';
                                break;
                }

	}

	string s;
	s += suite;
	s += " ";
	if (val>10)
	{
		int p = val-10;
		switch(p)
		{
			case 1 :s+="j";
			break;
			case 2 :s+="q";
			break;
		}
	} else if(val==1)
	{
		s+="a";
	}
	else if(val==0)
	{
		s+="k";
	}
	else {
		s+=std::to_string(val);
	}
	return s;
}


