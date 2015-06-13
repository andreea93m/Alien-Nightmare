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

void AlienNightmare::Warrior::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		glRotatef(270, 1, 0, 0);
		glRotatef(angle, 0, 0, 1);
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
	//std::cout<<direction;

	// go in front
	if(direction == 1){
		position.z+=speed;
		if(position.z + speed > scene->size.depth){
			angle = -90;
			direction = 0;
		}
	}
	// go left
	else if(direction == 0){
		position.x-=speed;
		if(position.x - speed < 0){
			angle = 180;
			direction = -1;
		}

	}
	// go back
	else if(direction == -1){
		position.z-=speed;
		if(position.z - speed < 0){
			angle = 90;
			direction = -2;
		}
	}
	// go right
	else if(direction == -2){
		position.x+=speed;
		if(position.x + speed > scene->size.width){
			angle = 360;
			direction = 1;
		}
	}
}

void AlienNightmare::Warrior::setSpeed(GLfloat speed){
	this->speed = speed;
}


