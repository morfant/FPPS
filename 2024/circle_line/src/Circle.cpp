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
    count = 0;
}

void Circle::draw()
{
    ofSetColor(color);
    float r = ofNoise(count) * radius;
    ofDrawCircle(pos.x, pos.y, r);
//    ofDrawCircle(pos.x, pos.y, radius);
    count += 0.01;
}

ofVec2f Circle::getPos()
{
    return pos;
}
