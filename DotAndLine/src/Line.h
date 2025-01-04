#pragma once
#include "Dot.h"

class Line : private Painter {
private:
	Dot* pointBegin;
	Dot* pointEnd;

public:
	Line() {};
	Line(Dot* d1, Dot* d2)
	{
		pointBegin = d1;
		pointEnd = d2;
	}

	void draw()
	{
		ofSetColor(
			makeRandomColor(),
			makeRandomColor(),
			makeRandomColor()
		);
		ofSetLineWidth(4);
		ofDrawLine(pointBegin->getX(), pointBegin->getY(), pointEnd->getX(), pointEnd->getY());
	}

};

