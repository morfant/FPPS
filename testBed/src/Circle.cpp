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
    mass = radius / 10.f;
    color = col;
    vel = ofVec2f(ofRandomf() * 10, ofRandomf() * 10);
    age = 0;
}

void Circle::applyForce(ofVec2f f)
{
    f = f / mass;
    acc.x += f.x;
    acc.y += f.y;
}

void Circle::pulled(ofVec2f t)
{
    // 힘의 크기를 보정하기 위한 임의의 값
    float magMul = 1500.f;
    
    ofVec2f r = t - pos; //  벡터 r
    float dist = r.length(); // 거리 r
    dist = ofClamp(dist, 15, 40); // 거리의 범위 제한 (15 ~ 40)
    
    // 정규화된 벡터 r hat
    ofVec2f rHat = r.normalize();
    
    // G = 1, m1 = 1, m2 = mass
    float mag = mass / (dist * dist);

    // r-hat을 방향으로 삼고, 그 크기를 mag로 만든 벡터 force
    ofVec2f force = rHat.scale(mag * magMul);

    applyForce(force);
}

void Circle::update()
{
    // 가속도를 이용한 속도 업데이트
    vel.x += acc.x;
    vel.y += acc.y;
    
    // 최대 속도 제한
    vel = vel.limit(TOP_SPEED);
    
    // 속도를 이용한 위치 업데이트
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
    
    // 누적 가속도 초기화
    acc = ofVec2f(0, 0);
    
    
//    age++;
    
    
}

void Circle::draw()
{
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, radius);
}

int Circle::getAge()
{
    return age;
}
