#pragma once
#include "ofMain.h"


class Painter
{
private:
	int value;


protected:
	int makeRandomColor()
	{
		value = rand() % 255;
		return value;
	}
	
public:
	Painter() {};
	Painter(int col) : value(col) {};


};

