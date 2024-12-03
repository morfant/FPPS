//
//  Circle.hpp
//  week13_basic
//
//  Created by Gang il Lee on 11/21/24.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "constants.h"


class Circle{
private:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    
    float mass;
    
    float rad;
    ofColor color;
    ofColor colorBase;
    float count;
    
    int age;
    
public:
    Circle(ofVec2f _pos, float _rad, ofColor _color);
    
    void applyForce(ofVec2f& f);
    void update();
    void draw();
    void checkEdge();
    
    int getAge();
    ofVec2f getPosition();
    float getMass();
    void setColorBase(const ofColor& col);

    void attract(Circle* other);
    
    
};


#endif /* Circle_hpp */
