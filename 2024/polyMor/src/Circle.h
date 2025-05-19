#pragma once
#include "ofMain.h"
#include "Shape.h"

class Circle : public Shape
{
private:
	float posX, posY;
	float velX, velY;
	float radius;

public:
	Circle() {};
	Circle(float x, float y, float r)
	{
		posX = x;
		posY = y;
		radius = r;
		velY = 0.5;
	}
	void update() override {
		posY = posY + velY;
	};

	void draw() override
	{
		ofSetColor(0, 100, 200);
		ofDrawCircle(posX, posY, radius);
	}

	void operator* (float f)
	{
		radius = radius * f;
	}

	void operator/ (float f)
	{
		radius = radius / f;
	}

	void operator+ (float f)
	{
		radius = radius + f;
	}

	void operator- (float f)
	{
		radius = radius - f;
	}







};

