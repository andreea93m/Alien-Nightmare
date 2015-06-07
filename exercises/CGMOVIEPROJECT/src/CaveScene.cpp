//
// Created by sorin on 5/30/15.
//

#include "../include/CaveScene.h"

AlienNightmare::CaveScene::CaveScene(Position position, Size size)
		: Scene(position, size),
		  fire(1000, Position(this, 0.5, 0.0, 0.5), Size(1, 0.1, 1)),
		  sun(Position(this, 0.5, 0.5, 0.5), 1), denmark(1.5, 120, "textures/denmark.png"),
		  germany(1.5, 0, "textures/germany.png"), poland(1.5, 180, "textures/poland.png") {
	denmark.placeRelative(this, 0.2, 0.0, 0.4);
	germany.placeRelative(this, 0.6, 0.0, 0.2);
	poland.placeRelative(this, 0.4, 0.0, 0.7);
}

void AlienNightmare::CaveScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		//drawWalls(0, 1, 0, 1);
		//sun.render(movieTime);
		fire.render(movieTime);
		denmark.render(movieTime);
		germany.render(movieTime);
		poland.render(movieTime);
		// drawFloor(0, 1, 0, 1);

	}
	glPopMatrix();
}

void AlienNightmare::CaveScene::update() {
	sun.update();
	denmark.update();
	fire.update();
}
