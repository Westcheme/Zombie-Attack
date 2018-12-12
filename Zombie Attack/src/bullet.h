#pragma once

#include "ofMain.h"

#include "circle.h"

class Bullet : public Circle
{
public:
	//Varibles
	ofImage bullet;
	ofSoundPlayer reloadSound;
	ofSoundPlayer firedSound;

	int numBullets;

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

	void reload();

	bool hits(Circle other);

	void bulletStop();
};