/*
 * Warrior.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: andreea
 */

#include <oogl/Model.h>
#include "../include/Warrior.h"

AlienNightmare::Warrior::Warrior(const AlienNightmare::Position &position, const AlienNightmare::Size &size) : Object(position, size) {
	model = (oogl::model::Model3ds *) oogl::loadModel("models/mech.3DS");
}

void AlienNightmare::Warrior::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		glRotatef(270, 1, 0, 0);
		glTranslatef(0, 1, 0);
		glScalef(2, 2, 2);
//		model->model->materials[1].ambient[3] = 0;
		model->textures[0]->bind(8);
		Shader::enableTexture(8);
		model->render();
		Shader::disableTexture();
	}
	glPopMatrix();
}

void AlienNightmare::Warrior::update() {

}



