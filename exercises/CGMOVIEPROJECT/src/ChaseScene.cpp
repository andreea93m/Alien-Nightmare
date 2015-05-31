//
// Created by sorin on 5/30/15.
//

#include "../include/ChaseScene.h"

AlienNightmare::ChaseScene::ChaseScene(Position position, Size size) : Scene(position, size) { }

void AlienNightmare::ChaseScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(1, 0, 0, 1);
		moveRelative(1 / 2.0f, 1 / 2.0f, 1 / 2.0f);
		drawDemo(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::ChaseScene::update() {

}
