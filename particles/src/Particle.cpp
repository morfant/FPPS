//
//  Particle.cpp
//  particles
//
//  Created by Gang il Lee on 1/5/25.
//

#include "Particle.hpp"

Particle::Particle(const glm::vec2& p)
{
    pos = p;
    
    vel = glm::vec2(ofRandomf(), ofRandomf());
    acc = glm::vec2(0, 0);
    
    lifeSpan = ofRandom(50, 400);
    radius = lifeSpan / 40.0;
    color = ofColor(255);
    age = 0;
    toDie = false;
}

void Particle::update()
{
    vel = vel + acc;
    pos = pos + vel;
    
}

void Particle::grow()
{
    age++;
    radius = (lifeSpan - age) / 40.0;

    if (age > lifeSpan)
    {
        toDie = true;
    }
}

bool Particle::hasToDie()
{
    return toDie;
}

void Particle::checkEdge()
{
    if (pos.x > WIDTH) pos.x = 0;
    else if (pos.x < 0) pos.x = WIDTH;
    if (pos.y > HEIGHT) pos.y = 0;
    else if (pos.y < 0) pos.y = HEIGHT;
}

void Particle::draw()
{
    ofSetColor(color);
    ofDrawCircle(pos, radius);
}

