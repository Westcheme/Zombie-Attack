#pragma once

#include "ofMain.h"

#include "circle.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

class ofApp : public ofBaseApp{

	public:

		Player player;
		Enemy enemies[10];
		Bullet bullet;



		ofTrueTypeFont myFont;

		ofImage mainMenu;

		ofImage gameOver;

		string gameState;








		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
