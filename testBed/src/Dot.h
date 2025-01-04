#pragma once
#include "ofMain.h"
#include "Painter.h"

class Line;

class Dot : public Painter {
private:
	int posX, posY, posZ;

public:
	Dot() {};
	Dot(int x, int y, int z) : posX(x), posY(y), posZ(z) {};
    
    Line operator+(Dot* other) ;

	int getX() { return posX; }
	int getY() { return posY; }
    int getZ() { return posZ; }

	void draw() {
		ofSetColor(
			makeRandomColor(),
			makeRandomColor(),
			makeRandomColor()
			);
		ofDrawCircle(posX, posY, posZ, 6);
	}
};




