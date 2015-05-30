//
// Created by sorin on 5/30/15.
//

#include "../include/RoomScene.h"

AlienNightmare::RoomScene::RoomScene(AlienNightmare::Scene::Position position, AlienNightmare::Scene::Size size)
		:Scene(position, size) { }

void AlienNightmare::RoomScene::render(float movieTime) {
	glPushMatrix();
	{
		glTranslatef(position.x, position.y, position.z);
		drawFloor(0, 0, 1, 1);
		drawDemo(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::RoomScene::update() {

}
