#pragma once
#include "ofMain.h"
#include "Shape.h"

class Dot : public Shape
{

private:
	int posX, posY;
	float radius;

public:
	Dot() {};
	Dot(int x, int y)
	{
		posX = x;
		posY = y;
		radius = 10;
	};

	void draw()
	{
		ofSetHexColor(hexCol);
		ofDrawCircle(posX, posY, radius);
	};

	int getX()
	{
		return posX;
	};

	int getY()
	{
		return posY;
	};

};

