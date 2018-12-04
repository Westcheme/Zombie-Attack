#pragma once

#include "ofMain.h"

#include "circle.h"

class Bullet : public Circle
{
public:
	//Varibles
	int vx, vy;

	int isFired;

	float xDistance;
	float yDistance;
	float magnitude;
	int speed;

	//Methods
	void setup();
	void update();
	void draw();

	void fired(Circle other);

	bool hits(Circle other);

	void bulletStop();
};