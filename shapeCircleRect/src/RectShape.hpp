//
//  RectShape.hpp
//  shapeCircleRect
//
//  Created by Gang il Lee on 1/3/25.
//

#ifndef RectShape_hpp
#define RectShape_hpp

#include <stdio.h>
#include "Shape.hpp"
#include "ofMain.h"

class RectShape : public Shape {
    
private:
    int width, height;
    float angle;
    
public:
    
    RectShape(int x, int y, int w, int h);
    void setup() override;
    void update() override;
    void draw() override;
    
};

#endif /* RectShape_hpp */
