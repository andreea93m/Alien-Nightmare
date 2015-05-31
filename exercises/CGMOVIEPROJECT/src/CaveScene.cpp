//
// Created by sorin on 5/30/15.
//

#include "../include/CaveScene.h"

AlienNightmare::CaveScene::CaveScene(Position position, Size size)
		: Scene(position, size) { }

void AlienNightmare::CaveScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(0, 1, 0, 1);
		moveRelative(1 / 2.0f, 1 / 2.0f, 1 / 2.0f);
		drawDemo(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::CaveScene::update() {

}
