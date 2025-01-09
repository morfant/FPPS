#include "Particle.h"

Particle::Particle(float x, float y, float r)
{
	posX = x;
	posY = y;
	lifeSpan = r;
	age = 0;

	velX = ofRandom(-2.0, 2.0);
	velY = ofRandom(-2.0, 2.0);

	radius = lifeSpan;

}


void Particle::update()
{
	posX = posX + velX;
	posY = posY + velY;

	if (posX - radius >= width) posX = 0 - radius;
	else if (posX + radius <= 0) posX = width + radius;

	if (posY - radius >= height) posY = 0 - radius;
	else if (posY + radius <= 0) posY = height + radius;

	if (radius > 0)
	{
		age += 0.02;
		radius = lifeSpan - age;
	}
}

bool Particle::toDie()
{
	if (lifeSpan <= age) return true;
	return false;
}

void Particle::draw()
{
	ofSetColor(255);
	ofDrawCircle(posX, posY, radius);
}
