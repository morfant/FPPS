#pragma once
#include "Painter.h"

class Dot;

class Line : private Painter {
private:
    vector<Dot*> dots;
    ofPath path;

public:
	Line() {};
    Line(Dot* d1, Dot* d2);
    
    void draw();
	
};

