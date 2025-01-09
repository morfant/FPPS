#pragma once
#include "ofMain.h"
#include "Dot.h"


class Line : public Shape {

private:
	Dot begin, end;

public:
	Line() {};
	Line(Dot d1, Dot d2)
	{
		begin = d1;
		end = d2;
	}

	void draw()
	{
		ofSetHexColor(hexCol);
		ofDrawLine(begin.getX(), begin.getY(), end.getX(), end.getY());
	}

};




