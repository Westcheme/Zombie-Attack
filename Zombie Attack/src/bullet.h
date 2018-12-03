#pragma once

#include "ofMain.h"

#include "circle.h"

class Bullet : public Circle
{
public:
	//Varibles
	int vx, vy;

	int isFired;

	//Methods
	void setup();
	void update();
	void draw();

	void fired(Circle other);
};