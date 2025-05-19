#pragma once
#include "ofMain.h"
class Circle {

private:
	float posX, posY;
	float radius;
	int color;

public:
	Circle(float x, float y, float r, int c);
	~Circle();
	void draw();
};

