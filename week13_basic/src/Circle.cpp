//
//  Point.cpp
//  week13_basic
//
//  Created by Gang il Lee on 11/21/24.
//

#include "Circle.hpp"


Circle::Circle(ofVec2f _pos, float _rad, ofColor _color)
{
    pos = _pos;
    rad = _rad;
    mass = rad / 10.f;
    color = _color;
    vel = ofPoint(ofRandomf(), 0);
    acc = ofPoint(0, 0);
    age = 0;
}

void Circle::update()
{
    // 가속도는 시간에 따른 속도의 변화량 (a = Δv/Δt)
    // Δv = a * Δt
    // 그러나 이 함수는 매 프레임 실행되기 때문에
    // 시간의 변화량은 '1 프레임 실행에 걸리는 시간'으로 일정하다.
    // Δv = a * 1 과 같이 다루기로 하자.
    // v_new = v_old + (a * 1)
    // v_new = v_old + a
    // 이전 속도에 가속도를 더하면 새로운 속도를 구할 수 있다
    vel = vel + acc;
    
    vel.limit(7);
    //    vel.x = ofClamp(vel.x, -40, 40);
    //    vel.y = ofClamp(vel.y, -40, 40);
    
    // 속도는 시간에 따른 위치의 변화량 (v = Δs/Δt)
    // 위의 경우와 마찬가지 이유로...
    // p_new = p_old + v
    // 이전 위치에 속도를 더하면 새로운 위치를 구할 수 있다
    pos = pos + vel;
    
    // acc reset
    acc.set(0, 0);
    //    acc.x = acc.x * 0.f;
    //    acc.y = acc.y * 0.f;
    
    age++;
}

int Circle::getAge()
{
    return age;
}


ofVec2f Circle::getPosition()
{
    return pos;
}

float Circle::getMass()
{
    return mass;
}

void Circle::checkEdge()
{
    if (pos.x + rad >= ofGetWidth())
    {
        pos.x = ofGetWidth() - rad; // 경계 안으로 위치 보정
        vel.x = vel.x * -1;
    }
    else if (pos.x - rad <= 0)
    {
        pos.x = rad;
        vel.x = vel.x * -1;
    }
    
    if (pos.y + rad >= ofGetHeight())
    {
        pos.y = ofGetHeight() - rad;
        vel.y = vel.y * -1;
    }
    else if (pos.y - rad <= 0)
    {
        pos.y = rad;
        vel.y = vel.y * -1;
    }
}

void Circle::applyForce(ofVec2f& f)
{
    acc.x = acc.x + (f.x / mass);
    acc.y = acc.y + (f.y / mass);
}

void Circle::attract(Circle* other)
{
    ofVec2f force = pos - other->getPosition();
    float r = ofClamp(force.length(), 5, 55);
    
    float strength = G * other->getMass() * mass / (r * r);
    force.scale(strength);
    
    other->applyForce(force);
}

void Circle::draw()
{
    int alpha = ofClamp(color.a - count, 0, color.a);
    ofSetColor(
               ofClamp(colorBase.r + color.r, 0, 255),
               ofClamp(colorBase.g + color.g, 0, 255),
               ofClamp(colorBase.b + color.b, 0, 255),
               255);
    ofDrawCircle(pos.x, pos.y, rad);
//    count++;
}



void Circle::setColorBase(const ofColor& col)
{
    colorBase = col;
}

