//
//  Circle.hpp
//  circle_line
//
//  Created by Gang il Lee on 12/4/24.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "ofMain.h"

class Circle {
    
private:
    ofVec2f pos;
    float count;
    float radius;
    ofColor color;
    
public:
    Circle(ofVec2f p);
    
    void draw();
    ofVec2f getPos();
    
};


#endif /* Circle_hpp */
