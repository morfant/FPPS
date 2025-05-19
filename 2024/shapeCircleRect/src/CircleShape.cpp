//
//  CircleShape.cpp
//  shapeCircleRect
//
//  Created by Gang il Lee on 1/3/25.
//

#include "CircleShape.hpp"

CircleShape::CircleShape(int x, int y, int r)
{
    posX = x;
    posY = y;
    radius = r;
}

void CircleShape::setup()
{
    fillColor.r = ofRandom(255);
    fillColor.g = ofRandom(255);
    fillColor.b = ofRandom(255);
    
    strokeColor.r = ofRandom(255);
    strokeColor.g = ofRandom(255);
    strokeColor.b = ofRandom(255);

}

void CircleShape::update()
{
    if (posX > WIDTH) posX = 0;
    else if (posX < 0) posX = WIDTH;
    
    if (posY > HEIGHT) posY = 0;
    else if (posY < 0) posY = HEIGHT;

    posX++;
    posY++;
}

void CircleShape::draw()
{
    
    ofNoFill();
    ofSetColor(strokeColor);
    ofDrawCircle(posX, posY, radius);
    
    ofFill();
    ofSetColor(fillColor);
    ofDrawCircle(posX, posY, radius);

}
