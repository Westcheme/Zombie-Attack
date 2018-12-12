#include "base.h"

void Base::setup()
{
	baseColor.set(100, 90, 70);
}

void Base::update()
{

}

void Base::draw()
{
	ofFill();
	ofSetColor(baseColor);
	ofDrawRectangle(400, 400, 200, 50);
	ofDrawRectangle(400, 600, 250, 50);
	ofDrawRectangle(400, 400, 50, 200);
	ofDrawRectangle(600, 400, 50, 200);
}