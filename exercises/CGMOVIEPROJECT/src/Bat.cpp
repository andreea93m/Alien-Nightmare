/*
 * Bat.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: andreea
 */

#include <oogl/Model.h>
#include "../include/Bat.h"

AlienNightmare::Bat::Bat(const AlienNightmare::Position &position, const AlienNightmare::Size &size) : Object(position, size), speed(0.0f) {
	model = (oogl::model::Model3ds *) oogl::loadModel("models/Bat/VAMP_BAT.3DS");
	initialPosition = position;
	up = 1;
}

void AlienNightmare::Bat::render() {
	glPushMatrix();
	{
//		position.y += movieTime * 0.001;
		moveToPosition();

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
	if(up == 1)
		position.y+=0.02 * delta * speed;
	else
		position.y -= 0.02 * delta * speed;

	if(position.y > speed/(speed*10)+initialPosition.y)	up = 0;
	if(position.y <= initialPosition.y)		up = 1;

	//glutPostRedisplay();
}
void AlienNightmare::Bat::setSpeed(GLfloat speed){
	this->speed = speed;
}
