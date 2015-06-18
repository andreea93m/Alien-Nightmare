//
// Created by sorin on 5/30/15.
//

#include "../include/ChaseScene.h"

AlienNightmare::ChaseScene::ChaseScene(Position position, Size size) : Scene(position, size),
																		germany(1.5, 0, "textures/germany.png"),
																		sun(Position(this, 0.5, 0.5, 0.5), 1),
																		animal(Position(this, 0.5, 0.5, 0.75), 1,1,1.5),
																		warrior(Position(this, 0.5, 0.2, 0.2), Size(1, 1, 1), this),
																		demoObject(Position(this, 0.5, 0.5, 0.5),
                                                                                  Size(1, 1, 1)) {
	germany.placeRelative(this, 0.8, 0, 0);
	germany.setJump(0.03, 5);
	germany.setJumpForward(0.045, this);
	warrior.setSpeed(0.03);
}

void AlienNightmare::ChaseScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(1, 0, 0, 1);
		sun.render(movieTime);
		animal.render(movieTime);
		germany.render(movieTime);
		warrior.render(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::ChaseScene::update() {
	sun.update();
	germany.update();
	warrior.update();
	animal.update();
}
