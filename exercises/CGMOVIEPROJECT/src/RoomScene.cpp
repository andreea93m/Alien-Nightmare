//
// Created by sorin on 5/30/15.
//

#include "../include/RoomScene.h"

AlienNightmare::RoomScene::RoomScene(Position position, Size size)
		: Scene(position, size) {

	Polandball * poland = new Polandball(1, 0, "textures/poland.png");
	poland->placeRelative(this, 0.3, 0, 0.3);

	Polandball * germany = new Polandball(1, 0, "textures/germany.png");
	germany->placeRelative(this, 0.6, 0, 0.9);

	Polandball * denmark = new Polandball(1, 0, "textures/denmark.png");
	denmark->placeRelative(this, 0.9, 0, 0.6);

	polandballs.push_back(poland);
	polandballs.push_back(germany);
	polandballs.push_back(denmark);
}

void AlienNightmare::RoomScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawFloor(0, 0, 1, 1);
		//drawWalls(0, 0, 1, 1);

		glColor3f(1, 1, 1);

		for(int i = 0; i < polandballs.size(); ++i) {
			polandballs[i]->render(movieTime);
		}
	}
	glPopMatrix();
}

void AlienNightmare::RoomScene::update() {
	for(int i = 0; i < polandballs.size(); ++i) {
		polandballs[i]->update();
	}
}
