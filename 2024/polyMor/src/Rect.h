#pragma once
#include "Shape.h"
#include "ofMain.h"

class Rect : public Shape
{
private:
	float posX, posY, width, height;
	float velX, velY;

public:
	Rect() {};
	Rect(float x, float y, float w, float h)
	{
		posX = x;
		posY = y;
		width = w;
		height = h;
		velX = 0.5;
	}

	void update() override {

		posX = posX + velX;


	};

	void draw() override {

		ofSetColor(100, 200, 0);
		ofDrawRectangle(posX, posY, width, height);
	
	};
};

