//
// Created by sorin on 5/30/15.
//

#include "../include/CaveScene.h"

AlienNightmare::CaveScene::CaveScene(Position position, Size size)
		: Scene(position, size),
		  fire(1000, Position(this, 0.5, 0.1, 0.5), Size(1, 0.1, 1)),
		  sun(Position(this, 0.5, 0.5, 0.5), 1), denmark(2, "textures/denmark.png") {
	denmark.placeRelative(this, 0.3, 0.0, 0.6);
}

void AlienNightmare::CaveScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		//drawFloor(0, 1, 0, 1);
		//drawWalls(0, 1, 0, 1);
		//sun.render(movieTime);
		denmark.render(movieTime);
		fire.render(movieTime);
	}
	glPopMatrix();
}

void AlienNightmare::CaveScene::update() {
	sun.update();
	denmark.update();
	fire.update();
}
