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
    
//    vel = ofVec2f(ofRandomf() * 10, ofRandomf() * 10);
    vel = ofVec2f(0, 0); // circle 객체의 초기 속도 (integer)
    age = 0;
}

void Circle::applyForce(ofVec2f f)
{
    acc.x += f.x;
    acc.y += f.y;
}

void Circle::update()
{
        
    // 이전 속도와 위치를 저장
    ofVec2f prevVel = vel;
    ofVec2f prevPos = pos;
 
//    vel.x += acc.x;
    
    if (isTouched == false)
    {
        vel.y += acc.y;
    }
    else
    {
        cout << "Velocity.y = " << vel.y << endl;
        isTouched = false;
    }
    
    cout << "Velocity.y = " << vel.y
         << ", Position.y = " << pos.y << endl;
    
//    pos.x += vel.x;
    pos.y += vel.y;
    
    // 충돌 감지 및 반사
    if (pos.x + radius >= ofGetWidth())
    {
      pos.x = ofGetWidth() - radius;
      vel.x = vel.x * -1;

      // 디버그 출력: x축 충돌
//      cout << "X Collision: Vel before = " << prevVel.x
//           << ", Vel after = " << vel.x
//           << ", Position correction = " << pos.x - prevPos.x << endl;
    }
    else if (pos.x - radius <= 0)
    {
      pos.x = radius;
      vel.x = vel.x * -1;

      // 디버그 출력: x축 충돌
//      cout << "X Collision: Vel before = " << prevVel.x
//           << ", Vel after = " << vel.x
//           << ", Position correction = " << pos.x - prevPos.x << endl;
    }

    if (pos.y + radius >= ofGetHeight())
    {
      pos.y = ofGetHeight() - radius;
      vel.y = vel.y * -1;

      // 디버그 출력: y축 충돌
      cout << "Y Collision: Vel before = " << prevVel.y
           << ", Vel after = " << vel.y
           << ", pos.y = " << pos.y
           << ", prePos.y = " << prevPos.y
           << ", Position correction = " << pos.y - prevPos.y << endl;
        isTouched = true;
    }
    else if (pos.y - radius <= 0)
    {
      pos.y = radius;
      vel.y = vel.y * -1;

      // 디버그 출력: y축 충돌
      cout << "Y Collision: Vel before = " << prevVel.y
           << ", Vel after = " << vel.y
           << ", Position correction = " << pos.y - prevPos.y << endl;
    }
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
