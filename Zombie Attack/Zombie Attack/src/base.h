#pragma once

#include "ofMain.h"

class Base : public ofRectangle
{
public:

	//Varibles
	ofRectangle baseNorth;
	ofRectangle baseSouth;
	ofRectangle baseEast;
	ofRectangle baseWest;

	//Methods
	void setup();
	void update();
	void draw();
};