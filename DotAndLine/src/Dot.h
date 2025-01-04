#pragma once
#include "ofMain.h"
#include "Painter.h"

class Dot : public Painter {
private:
	int posX, posY;

public:
	Dot() {};
	Dot(int x, int y) : posX(x), posY(y) {};

	int getX() { return posX; }
	int getY() { return posY; }

	void draw() {
		ofSetColor(
			makeRandomColor(),
			makeRandomColor(),
			makeRandomColor()
			);
		ofDrawCircle(posX, posY, 6);
	}
};




