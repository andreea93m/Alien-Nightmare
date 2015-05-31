//
// Created by sorin on 5/30/15.
//

#include "../include/RoomScene.h"

AlienNightmare::RoomScene::RoomScene(Position position, Size size)
		: Scene(position, size) { }

void AlienNightmare::RoomScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(0, 0, 1, 1);
		moveRelative(1 / 2.0f, 1 / 2.0f, 1 / 2.0f);
		drawDemo(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::RoomScene::update() {

}
