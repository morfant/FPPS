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
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    float mass;

    float damping = 1;
    float range = 200;
    
public:
    static float TOP_SPEED;
    Circle(ofVec2f& _pos, float _radius);
    
    void draw();
    void update();
    void applyForce(ofVec2f f);
    void pulled(ofVec2f target);
    void repelled(ofVec2f target);
};



#endif /* Circle_hpp */
