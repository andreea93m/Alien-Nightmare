//
// Created by sorin on 5/30/15.
//

#include "../include/CaveScene.h"

AlienNightmare::CaveScene::CaveScene(Position position, Size size)
		: Scene(position, size) { }

void AlienNightmare::CaveScene::render(float movieTime) {
	glPushMatrix();
	{
		glTranslatef(position.x, position.y, position.z);
		drawFloor(0, 1, 0, 1);

		drawDemo(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::CaveScene::update() {

}
