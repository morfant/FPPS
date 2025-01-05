//
//  Particle.hpp
//  particles
//
//  Created by Gang il Lee on 1/5/25.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle {
private:
    glm::vec2 pos, vel, acc;
    ofColor color;
    float radius;
    int age, lifeSpan;
    bool toDie;
    
    
public:
    Particle() {};
    Particle(const glm::vec2& p);
    
    void update();
    void checkEdge();
    void grow();
    void draw();
    bool hasToDie();
    
    static int WIDTH;
    static int HEIGHT;
    
};

#endif /* Particle_hpp */
