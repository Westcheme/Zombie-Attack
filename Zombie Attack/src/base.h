#pragma once

#include "ofMain.h"

class Base : public ofRectangle
{
public:

	//Varibles
	ofColor baseColor;

	//Methods
	void setup();
	void update();
	void draw();
};