//
//  Circle.cpp
//  circle_line
//
//  Created by Gang il Lee on 12/4/24.
//

#include "Circle.hpp"

Circle::Circle(ofVec2f p)
{
    pos = p;
    radius = ofRandom(10, 80);
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}


void Circle::draw()
{
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, ofRandom(radius));
//    ofDrawCircle(pos.x, pos.y, radius);
}

ofVec2f Circle::getPos()
{
    return pos;
}
