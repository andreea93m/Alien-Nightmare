//
// Created by sorin on 5/30/15.
//

#include "../include/ChaseScene.h"

AlienNightmare::ChaseScene::ChaseScene(Position position, Size size) : Scene(position, size),
																		germany(1.5, 0, "textures/germany.png"),
																		sun(Position(this, 0.5, 0.5, 0.5), 1),
																		warrior(Position(this, 0.5, 0.2, 0.2), Size(1, 1, 1)),
																		demoObject(Position(this, 0.5, 0.5, 0.5),
                                                                                  Size(1, 1, 1)) {
	germany.placeRelative(this, 0.5, 0, 0.4);
}

void AlienNightmare::ChaseScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(1, 0, 0, 1);
		sun.render(movieTime);
		germany.render(movieTime);
		warrior.render(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::ChaseScene::update() {
	sun.update();
	germany.update();

}
