#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	ofSetCircleResolution(100);

	myFont.load("bloody.otf", 60);
	mainMenu.load("zombies.jpg");

	gameState = 0;


	ofSetBackgroundColor(0, 80, 0);

	player.setup();
	bullet.setup();

	for (int i = 0; i < 10; i++)
	{
		enemies[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	player.update();
	bullet.update();

	for (int i = 0; i < 10; i++)
	{
		enemies[i].update();
		if (player.intersects(enemies[i]) == true) player.health = player.health - 1;
		if (bullet.intersects(enemies[i]) == true) enemies[i].dead();
	}
	if (player.health <= 0) player.health = 0;
}

//--------------------------------------------------------------
void ofApp::draw()
{	
	if (gameState == 0)
	{
		mainMenu.draw(0, 0);

		myFont.drawString("Zombie Assault", 100, 400);
		myFont.drawString("Press TAB to start the game", 100, 475);
	}

	if (gameState == 1)
	{
		player.draw();
		bullet.draw();

		for (int i = 0; i < 10; i++)
		{
			enemies[i].draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'w') player.up();
	if (key == 's') player.down();
	if (key == 'a') player.left();
	if (key == 'd') player.right();

	if (key == OF_KEY_TAB) gameState = 1;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (button == 0) bullet.fired(player);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
