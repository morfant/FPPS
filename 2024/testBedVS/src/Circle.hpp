//
//  Circle.hpp
//  week_13
//
//  Created by Gang il Lee on 11/27/24.
//

#ifndef Circle_hpp
#define Circle_hpp


#include <stdio.h>
#include "ofMain.h"

class Circle {
    
private:
    float radius;
    float mass;
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    ofColor color;
    int age;
    
public:
    
    Circle(ofVec2f& _pos, float _radius, ofColor col);
    
    void draw();
    void update();
    void applyForce(ofVec2f f);
    void pulled(ofVec2f t);
    int getAge();
    
    static float TOP_SPEED;
};



#endif /* Circle_hpp */
