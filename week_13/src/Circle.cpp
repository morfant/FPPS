//
//  Circle.cpp
//  week_13
//
//  Created by Gang il Lee on 11/27/24.
//

#include "Circle.hpp"

Circle::Circle(ofVec2f& p, float r, ofColor col)
{
    pos = p;
    radius = r;
    color = col;
    vel = ofVec2f(ofRandomf() * 10, 0);
    age = 0;
    mass = radius / 10.f;
}

void Circle::applyForce(ofVec2f f)
{
    f = f / mass;
    acc.x += f.x;
    acc.y += f.y;
}

void Circle::update()
{
    vel.x += acc.x;
    vel.y += acc.y;
    
    vel = vel.limit(20);
    
    pos.x += vel.x;
    pos.y += vel.y;
    
    // 충돌 감지 및 반사
    if (pos.x + radius >= ofGetWidth())
    {
      pos.x = ofGetWidth() - radius;
      vel.x = vel.x * -1;
    }
    else if (pos.x - radius <= 0)
    {
      pos.x = radius;
      vel.x = vel.x * -1;
    }

    if (pos.y + radius >= ofGetHeight())
    {
      pos.y = ofGetHeight() - radius;
      vel.y = vel.y * -1;
    }
    else if (pos.y - radius <= 0)
    {
      pos.y = radius;
      vel.y = vel.y * -1;
    }
    
    acc = ofVec2f(0, 0);
    
    
//    age++;
    
    
}

void Circle::draw()
{
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, radius);
}

void Circle::pulled(ofVec2f t)
{
//    ofVec2f dir = t - pos; // r
    ofVec2f dir = pos - t; // r
    dir = dir.normalize(); // 정규화된 벡터 r-hat

    float d = dir.length(); // 거리 r
    d = ofClamp(d, 15, 40);

        // G = 1, m1 = 1, m2 = mass
    float mag = mass / d * d;

        // r-hat을 방향으로 삼고, 그 크기를 mag로 만든다.
    ofVec2f force = dir.scale(mag);

    applyForce(force);
}

int Circle::getAge()
{
    return age;
}
