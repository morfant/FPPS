#pragma once
#include <cstdlib>

class Shape
{
private:

protected:
	int hexCol = 0x000000;
	int colors[5] = { 0x292f36, 0x4ecdc4, 0xf7fff7, 0xff6b6b, 0xffe66d };

public:
	void changeColor()
	{
		int randIdx = rand() % 5;
		hexCol = colors[randIdx];
	}

};

