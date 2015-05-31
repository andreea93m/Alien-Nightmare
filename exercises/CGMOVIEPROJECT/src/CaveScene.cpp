//
// Created by sorin on 5/30/15.
//

#include "../include/CaveScene.h"

AlienNightmare::CaveScene::CaveScene(Position position, Size size)
		: Scene(position, size), demoObject(Position(this, 0.5, 0.5, 0.5), Size(1, 1, 1)) {
}

void AlienNightmare::CaveScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(0, 1, 0, 1);
		demoObject.render(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::CaveScene::update() {

}
