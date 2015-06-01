//
// Created by sorin on 5/30/15.
//

#include "../include/ChaseScene.h"

AlienNightmare::ChaseScene::ChaseScene(Position position, Size size) : Scene(position, size),
                                                                       demoObject(Position(this, 0.5, 0.5, 0.5),
                                                                                  Size(1, 1, 1)) { }

void AlienNightmare::ChaseScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(1, 0, 0, 1);
		drawWalls(1, 0, 0, 1);
		demoObject.render(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::ChaseScene::update() {

}
