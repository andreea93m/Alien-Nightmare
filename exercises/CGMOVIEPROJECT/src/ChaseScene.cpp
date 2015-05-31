//
// Created by sorin on 5/30/15.
//

#include "../include/ChaseScene.h"

AlienNightmare::ChaseScene::ChaseScene(Position position, Size size) : Scene(position, size) { }

// The definitions of the overwritten function
void AlienNightmare::ChaseScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

		drawFloor(1, 0, 0, 1);
		drawDemo(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::ChaseScene::update() {

}
