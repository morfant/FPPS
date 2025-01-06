#pragma once
#include "ofMain.h"

class Dot
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
		ofSetColor(142, 85, 114);
		ofDrawCircle(posX, posY, radius);
	}

	float getRadius() { return radius; }
	int getX() { return posX; }
	int getY() { return posY; }


};

