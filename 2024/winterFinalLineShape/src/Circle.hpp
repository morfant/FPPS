//
//  Circle.hpp
//  winterFinalLineShape
//
//  Created by Gang il Lee on 1/9/25.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "ofMain.h"

class Circle{
    
private:
    float posX, posY, radius;
    ofColor col;
    
    
public:
    Circle(float x, float y)
    {
        posX = x;
        posY = y;
        radius = ofRandom(10, 100);
        col = ofColor(ofRandom(255));
    }
    
    void draw()
    {
        ofSetColor(col);
        ofDrawCircle(posX, posY, radius);
    }
    
};

#endif /* Circle_hpp */
