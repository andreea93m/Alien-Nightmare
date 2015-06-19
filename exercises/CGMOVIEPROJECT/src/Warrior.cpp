/*
 * Warrior.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: andreea
 */

#include <oogl/Model.h>
#include "../include/Warrior.h"

AlienNightmare::Warrior::Warrior(const AlienNightmare::Position &position, const AlienNightmare::Size &size, AlienNightmare::Scene *scene)
								: Object(position, size) {
	model = (oogl::model::Model3ds *) oogl::loadModel("models/mech.3DS");
	initialPosition = position;
	this->scene = scene;
	angle = 90;
	direction = -2;
}

void AlienNightmare::Warrior::render() {
	glPushMatrix();
	{
		moveToPosition();
		glRotatef(270, 1, 0, 0);
		glRotatef(angle, 0, 0, 1);
		glTranslatef(0, 1, 0);
		glScalef(2, 2, 2);
		model->textures[0]->bind(8);
		Shader::enableTexture(8);
		model->render();
		Shader::disableTexture();
	}
	glPopMatrix();
}

void AlienNightmare::Warrior::update(float delta) {

	// go in front
	if(direction == 1){
		position.z+=delta * speed;
		if(position.z > scene->size.depth - 1){
			angle = -90;
			direction = 0;
		}
	}
	// go left
	else if(direction == 0){
		position.x-=delta * speed;
		if(position.x < 1){
			angle = 180;
			direction = -1;
		}

	}
	// go back
	else if(direction == -1){
		position.z-=delta * speed;
		if(position.z  < 1){
			angle = 90;
			direction = -2;
		}
	}
	// go right
	else if(direction == -2){
		position.x+=delta * speed;
		if(position.x  > scene->size.width - 1){
			angle = 360;
			direction = 1;
		}
	}
}

void AlienNightmare::Warrior::setSpeed(GLfloat speed){
	this->speed = speed;
}


