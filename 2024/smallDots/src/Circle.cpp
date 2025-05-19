//
//  Circle.cpp
//  week_13
//
//  Created by Gang il Lee on 11/27/24.
//

#include "Circle.hpp"

Circle::Circle(ofVec2f& p, float r)
{
    pos = p;
    radius = r;
    mass = radius / 10.f;
    vel = ofVec2f(ofRandomf() * 10, ofRandomf() * 10);
}


void Circle::update()
{

    vel.x += acc.x;
    vel.y += acc.y;

    vel = vel.limit(TOP_SPEED);

    pos.x += vel.x;
    pos.y += vel.y;

    
    if (pos.x + radius >= ofGetWidth()) {
        pos.x = ofGetWidth() - radius;
        vel.x *= -1;
        vel.x *= damping;
    }
    else if (pos.x - radius <= 0) {
        pos.x = radius;
        vel.x *= -1;
        vel.x *= damping;
    }


    if (pos.y + radius >= ofGetHeight()) {
        pos.y = ofGetHeight() - radius;
        vel.y *= -1;
        vel.y *= damping;
    }
    else if (pos.y - radius <= 0) {
        pos.y = radius;
        vel.y *= -1;
        vel.y *= damping;
    }

    acc.set(0, 0);
}

void Circle::draw()
{
    ofSetColor(0, 20);
    ofDrawCircle(pos.x, pos.y, radius);
}



void Circle::applyForce(ofVec2f f)
{
    f /= mass;
    acc.x = acc.x + f.x;
    acc.y = acc.y + f.y;
}


void Circle::pulled(ofVec2f t)
{
    ofVec2f dir = t - pos;
    dir = dir.normalize();

    float d = dir.length();
    //float d = ofDist(t.x, t.y, pos.x, pos.y);
    d = ofClamp(d, 15, 40);

    float mag = mass / d * d;

    ofVec2f force = dir.scale(mag);

    applyForce(force);
}


void Circle::repelled(ofVec2f t)
{
    float d = ofDist(t.x, t.y, pos.x, pos.y);
    if (d < range) {
		ofVec2f dir = pos - t;
		dir = dir.normalize();

		d = ofClamp(d, 15, 40);

		float mag = mass / d * d;

		ofVec2f force = dir.scale(mag);

		applyForce(force);
	}

}


