//
//  CircleShape.hpp
//  shapeCircleRect
//
//  Created by Gang il Lee on 1/3/25.
//

#ifndef CircleShape_hpp
#define CircleShape_hpp

#include <stdio.h>
#include "Shape.hpp"
#include "ofMain.h"

class CircleShape : public Shape {
    
private:
    int radius;
    
public:
    CircleShape(int x, int y, int r);
    void setup() override;
    void update() override;
    void draw() override;
    
};

#endif /* CircleShape_hpp */
