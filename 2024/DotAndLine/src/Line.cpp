#include "Line.h"
#include "Dot.h"


Line::Line(Dot* d1, Dot* d2)
{
    dots.push_back(d1);
    dots.push_back(d2);
}

void Line::draw()
{
    path.setStrokeColor(ofColor(
        makeRandomColor(),
        makeRandomColor(),
        makeRandomColor()
    ));
    path.setStrokeWidth(4);
    
    path.moveTo(dots.at(0)->getX(), dots.at(0)->getY(), dots.at(0)->getZ());
    dots.at(0)->draw();
    for (int i = 1; i < dots.size(); i++)
    {
        path.lineTo(dots.at(i)->getX(), dots.at(i)->getY(), dots.at(i)->getZ());
        dots.at(i)->draw();
    }
    
    
    path.close();
    path.draw();
}
