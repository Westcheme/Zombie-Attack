#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofSetCircleResolution(100);

	myFont.load("bloody.otf", 60);
	mainMenu.load("zombies.jpg");
	gameOver.load("gameover.jpg");

	gameState = "mainMenu";

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
	if (gameState == "inGame")
	{
		player.update();
		bullet.update();

		for (int i = 0; i < 10; i++)
		{
			enemies[i].update();
			if (enemies[i].hits(player) == true) player.health = player.health - 1;
			if (bullet.hits(enemies[i]) == true && enemies[i].isAlive == "alive")
			{
				enemies[i].takeDamage();
				bullet.bulletStop();
			}

			enemies[i].seek(player);
		}

		if (player.health <= 0) gameState = "gameOver";
		if (gameState == "gameOver") ofSetBackgroundColor(0, 0, 0);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{	
	if (gameState == "mainMenu")
	{
		ofSetColor(255, 255, 255);
		mainMenu.draw(0, 0);

		ofSetColor(255, 0, 0);
		myFont.drawString("Zombie Assault", 100, 400);
		myFont.drawString("Press TAB to start the game", 100, 475);
	}
	if (gameState == "inGame")
	{
		player.draw();
		bullet.draw();

		for (int i = 0; i < 10; i++)
		{
			enemies[i].draw();
		}
	}
	if (gameState == "gameOver")
	{
		ofSetColor(255, 255, 255);
		gameOver.draw(-130, 100);

		ofSetColor(134, 0, 0);
		myFont.drawString("Press TAB To Try Again", 250, 600);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (gameState == "inGame")
	{
		if (key == 'w') player.up();
		if (key == 's') player.down();
		if (key == 'a') player.left();
		if (key == 'd') player.right();

		if (key == 'r') bullet.reload();
	}
	if (gameState == "mainMenu")
	{
		if (key == OF_KEY_TAB) gameState = "inGame";
	}
	if (gameState == "gameOver")
	{
		if (key == OF_KEY_TAB) gameState = "mainMenu";
	}
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
	if (gameState == "inGame")
	{
		if (button == 0) bullet.fired(player);
	}
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
