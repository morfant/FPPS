#include "Circle.h"

Circle::Circle(float x, float y, float r, int c)
	: posX(x), posY(y), radius(r), color(c){}

Circle::~Circle() {
	
}

void Circle::draw() {
	
	ofSetColor(color);
	ofDrawCircle(posX, posY, radius);
}
