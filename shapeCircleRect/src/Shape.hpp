//
//  Shape.hpp
//  shapeCircleRect
//
//  Created by Gang il Lee on 1/3/25.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include "ofMain.h"

class Shape{
    
public:
    int posX, posY;
    ofColor fillColor, strokeColor;
    static int WIDTH, HEIGHT;
    
    
    Shape(){};
    virtual void setup() {};
    virtual void update() {};
    virtual void draw() = 0;
    
    
    
};

#endif /* Shape_hpp */
