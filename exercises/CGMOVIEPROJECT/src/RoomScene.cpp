//
// Created by sorin on 5/30/15.
//

#include "../include/RoomScene.h"

// The definitions of the overwritten function
void AlienNightmare::RoomScene::render(float movieTime) {
	glPushMatrix();
	{
		glTranslatef(spacing(), 0, 0);
		Scene::render(movieTime);
	}
	glPopMatrix();
}
