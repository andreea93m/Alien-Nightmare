/*
 * Bat.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: andreea
 */

#include <oogl/Model.h>
#include "../include/Bat.h"

AlienNightmare::Bat::Bat(const AlienNightmare::Position &position, const AlienNightmare::Size &size) : Object(position,
                                                                                                              size),
                                                                                                       speed(0.0f) {
	model = (oogl::model::Model3ds *) oogl::loadModel("models/Bat/VAMP_BAT.3DS");
	initialPosition = position;
	up = 1;
}

void AlienNightmare::Bat::render() {
	glPushMatrix();
	{
		moveToPosition();
		glRotatef(90,1,0,0);
		glTranslatef(0, 1, 0);
		glScalef(2, 2, 2);
		model->textures[0]->bind(7);
		Shader::enableTexture(7);
		model->render();
		Shader::disableTexture();
	}
	glPopMatrix();
}

void AlienNightmare::Bat::update(float delta) {
	if (up == 1) {
		position.y += 0.02 * delta * speed;
	}
	else {
		position.y -= 0.02 * delta * speed;
	}

	// change position on y axis to simulate flight
	if (position.y > speed*30 + initialPosition.y) { up = 0; }
	else { up = 1; }
}

void AlienNightmare::Bat::setSpeed(GLfloat speed) {
	this->speed = speed;
}
