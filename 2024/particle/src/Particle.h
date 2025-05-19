#pragma once
#include "ofMain.h"

class Particle
{
private:
	float posX, posY;
	float velX, velY;
	float radius;
	int lifeSpan;
	float age;

public:

	static int width;
	static int height;

	Particle(float x, float y, float r);

	void update();
	void draw();
	bool toDie();

};

