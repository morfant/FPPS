//
//  RectShape.cpp
//  shapeCircleRect
//
//  Created by Gang il Lee on 1/3/25.
//

#include "RectShape.hpp"

RectShape::RectShape(int x, int y, int w, int h)
{
    posX = x;
    posY = y;
    width = w;
    height = h;
    
}

void RectShape::setup()
{
    fillColor.r = ofRandom(255);
    fillColor.g = ofRandom(255);
    fillColor.b = ofRandom(255);
    
    strokeColor.r = ofRandom(255);
    strokeColor.g = ofRandom(255);
    strokeColor.b = ofRandom(255);
}

void RectShape::update()
{
   
    angle += 1;
    
}

void RectShape::draw()
{
    
    ofPushMatrix();
    ofTranslate(posX + width * 0.5, posY + height * 0.5);
    ofRotateZDeg(angle);
    
    ofNoFill();
    ofSetColor(strokeColor);
    ofDrawRectangle(-width * 0.5, -height * 0.5, width, height);
    
    ofFill();
    ofSetColor(fillColor);
    ofDrawRectangle(-width * 0.5, -height * 0.5, width, height);
    
    ofPopMatrix();

    
}
