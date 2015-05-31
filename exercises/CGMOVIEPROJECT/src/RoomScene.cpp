//
// Created by sorin on 5/30/15.
//

#include "../include/RoomScene.h"

AlienNightmare::RoomScene::RoomScene(Position position, Size size)
		: Scene(position, size), demoObject(Position(this, 0.5, 0.5, 0.5), Size(1, 1, 1)) { }

void AlienNightmare::RoomScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(0, 0, 1, 1);
		demoObject.render(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::RoomScene::update() {

}
