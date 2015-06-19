//
// Created by sorin on 5/30/15.
//

#include "../include/CaveScene.h"

AlienNightmare::CaveScene::CaveScene(Position position, Size size)
		: Scene(position, size),
		  fire(1000, Position(this, 0.5, 0.0, 0.5), Size(1, 0.1, 1)),
		  bat(Position(this, 0.5, 0.3, 0.5), Size(1, 1, 1)),
		  denmark(1, 120, "textures/denmark.png"),
		  germany(1, 0, "textures/germany.png"), poland(1, 180, "textures/poland.png"),
		  alien(Position(this, 0.1, 0.0, 0.0), Size(1, 1, 1)){
	denmark.placeRelative(this, 0.2, 0.0, 0.4);
	germany.placeRelative(this, 0.6, 0.0, 0.2);
	poland.placeRelative(this, 0.4, 0.0, 0.7);
	bat.setSpeed(.005);
}

void AlienNightmare::CaveScene::render() {
	glPushMatrix();
	{
		moveToPosition();
		drawWalls(0, 1, 0, 1);
		fire.render();
		bat.render();
		denmark.render();
		germany.render();
		poland.render();
		alien.render();

	}
	glPopMatrix();
}

void AlienNightmare::CaveScene::update(float delta) {
	denmark.update(delta);
	germany.update(delta);
	poland.update(delta);
	fire.update(delta);
	bat.update(delta);
	alien.update(delta);
}
