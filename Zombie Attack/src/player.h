#pragma once

#include "ofMain.h"

#include "circle.h"

class Player : public Circle
{
public:

	int health;
	int healthx;
	int healthy;
	int width;
	int height;

	int bulletx;
	int bullety;
	int bulletvx;
	int bulletvy;
	int bulletr;

	void setup();
	void update();
	void draw();

	float up();
	float down();
	float left();
	float right();

	void fireBullet();
};