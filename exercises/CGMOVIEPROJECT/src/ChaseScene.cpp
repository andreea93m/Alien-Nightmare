//
// Created by sorin on 5/30/15.
//

#include "../include/ChaseScene.h"

// The definitions of the overwritten function
void AlienNightmare::ChaseScene::render(float movieTime) {
	glPushMatrix();
	{
		glTranslatef(0, 0, 0);
		Scene::render(movieTime);
	}
	glPopMatrix();
}
