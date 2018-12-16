#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofSetCircleResolution(100);

	myFont.load("bloody.otf", 60);
	mainMenu.load("mainmenu.png");
	gameOver.load("gameover.jpg");

	gameState = "mainMenu";

	player.setup();
	bullet.setup();

	for (int i = 0; i < 10; i++)
	{
		enemies[i].setup();
	}

	cout << gameState;
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
				if (enemies[i].health <= 0)
				{
					enemies[i].isAlive = "dead";
					player.score = player.score + 10;
				}

				bullet.bulletStop();
			}

			enemies[i].seek(player);
		}

		if (player.score == 100) gameState = "youWon";

		if (player.health <= 0) gameState = "gameOver";
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{	
	if (gameState == "mainMenu")
	{
		ofSetBackgroundColor(0, 0, 0);

		ofSetColor(255, 255, 255);
		mainMenu.draw(50, 100, 900, 300);

		ofSetColor(255, 0, 0);
		myFont.drawString("Press TAB to start the game", 100, 475);

		myFont.drawString("Press I to see the instructions", 100, 550);
	}
	if (gameState == "instructions")
	{
		ofSetBackgroundColor(0, 0, 0);

		ofSetColor(255, 0, 0);
		myFont.drawString("The apocalypse has begun and you", 50, 100);
		myFont.drawString("are attacked by a horde of zombies,", 50, 175);
		myFont.drawString("you must defend your life with", 50, 250);
		myFont.drawString("nothing but your trusty handgun.", 50, 325);

		myFont.drawString("Use W A S D to move the player", 50, 500);
		myFont.drawString("and left mouse to shoot.", 50, 575);
		myFont.drawString("BACKSPACE if you would", 50, 650);
		myFont.drawString("like to pause the game.", 50, 725);

		myFont.drawString("Press TAB to start the game", 50, 900);
	}
	if (gameState == "inGame")
	{
		ofSetBackgroundColor(0, 80, 0);

		player.draw();
		bullet.draw();

		for (int i = 0; i < 10; i++)
		{
			enemies[i].draw();
		}
	}
	if (gameState == "paused")
	{
		ofSetBackgroundColor(0, 0, 0);

		ofSetColor(255, 0, 0);
		myFont.drawString("PAUSED", 450, 500);

		myFont.drawString("Press TAB to resume", 275, 600);
	}
	if (gameState == "gameOver")
	{
		player.health = 100;

		ofSetBackgroundColor(0, 0, 0);

		ofSetColor(255, 255, 255);
		gameOver.draw(-130, 100);

		ofSetColor(134, 0, 0);
		myFont.drawString("Press TAB To Try Again", 250, 600);

		player.setup();
		bullet.setup();

		for (int i = 0; i < 10; i++)
		{
			enemies[i].setup();
		}
	}
	if (gameState == "youWon")
	{
		player.health = 100;

		ofSetBackgroundColor(0, 0, 0);

		ofSetColor(134, 0, 0);
		myFont.drawString("Congratulations You Won", 200, 500);

		myFont.drawString("Press TAB To Play Again", 200, 600);

		player.setup();
		bullet.setup();

		for (int i = 0; i < 10; i++)
		{
			enemies[i].setup();
		}
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

		if (key == OF_KEY_BACKSPACE) gameState = "paused";
	}
	if (gameState == "mainMenu")
	{
		if (key == OF_KEY_TAB) gameState = "inGame";

		if (key == 'i') gameState = "instructions";
	}
	if (gameState == "instructions")
	{
		if (key == OF_KEY_TAB) gameState = "inGame";
	}
	if (gameState == "paused")
	{
		if (key == OF_KEY_TAB) gameState = "inGame";
	}
	if (gameState == "gameOver")
	{
		if (key == OF_KEY_TAB) gameState = "mainMenu";
	}
	if (gameState == "youWon")
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
