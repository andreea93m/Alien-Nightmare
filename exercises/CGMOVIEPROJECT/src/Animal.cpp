/*
 * Animal.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: andreea
 */

#include <oogl/Texture.h>
#include "../include/Animal.h"

AlienNightmare::Animal::Animal(const AlienNightmare::Position &position,
		GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ, Scene *scene) :
		Object(position, Size(sizeX, sizeY, sizeZ)), body(Position(0, 0, 0),
				sizeX, sizeY, sizeZ, "textures/cat_fur.jpg"), leftFrontLeg(
				Position(&body, -0.4, -0.8, 0.3), 0.1, 1, 0.2, "textures/cat_fur.jpg"), rightFrontLeg(
				Position(&body, 0.4, -0.8, 0.2), 0.1, 1, 0.3, "textures/cat_fur.jpg"), leftBackLeg(
				Position(&body, -0.4, -0.8, -0.3), 0.1, 1, 0.2, "textures/cat_fur.jpg"), rightBackLeg(
				Position(&body, 0.4, -0.8, -0.3), 0.1, 1, 0.2, "textures/cat_fur.jpg"), head(1.5, 0,
				"textures/cat_head.jpg"), initialPosition(position) {

	speed = 0.0f;
	walkingAngle = 90;
	this->scene = scene;
	walkingDirection = -2;
	walkingSpeed = 0;
	head.placeRelative(&body, -0.8, 0, 0);
	leftFrontLeg.setProperties(-30, -1);
	leftBackLeg.setProperties(30, 1);
	rightBackLeg.setProperties(30, 1);
	rightFrontLeg.setProperties(-30, -1);
}

void AlienNightmare::Animal::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		glRotatef(walkingAngle, 0, 1, 0);
		head.render(movieTime);
		body.render(movieTime);
		leftFrontLeg.render(movieTime);
		rightFrontLeg.render(movieTime);
		leftBackLeg.render(movieTime);
		rightBackLeg.render(movieTime);

	}
	glPopMatrix();
}

void AlienNightmare::Animal::setJump(GLfloat speed, GLfloat height,
		GLfloat walkingSpeed) {
	this->speed = speed;
	this->maxHeight = height;
	this->walkingSpeed = walkingSpeed;
	body.setJump(speed, height);
	head.setJump(speed, height+1.5);
	leftBackLeg.setJump(speed, height);
	rightBackLeg.setJump(speed, height);
	leftFrontLeg.setJump(speed, height);
	rightFrontLeg.setJump(speed, height);

}

void AlienNightmare::Animal::update() {
	head.update();
	body.update();
	leftBackLeg.update();
	rightBackLeg.update();
	leftFrontLeg.update();
	rightFrontLeg.update();
	// go in front
	if (walkingDirection == 1) {
		position.z += walkingSpeed;
		if (position.z + walkingSpeed > scene->size.depth - 1) {
			walkingAngle = -90;
			walkingDirection = 0;
		}
	}
//	 go left
	else if (walkingDirection == 0) {
		position.x -= walkingSpeed;
		if (position.x - walkingSpeed < 1) {
			walkingAngle = 180;
			walkingDirection = -1;
		}

	}
	// go back
	else if (walkingDirection == -1) {
		position.z -= walkingSpeed;
		if (position.z - walkingSpeed < 1) {
			walkingAngle = 90;
			walkingDirection = -2;
		}
	}
	// go right
	else if (walkingDirection == -2) {
		position.x += walkingSpeed;
		if (position.x + walkingSpeed > scene->size.width - 1) {
			walkingAngle = 360;
			walkingDirection = 1;
		}
	}

}
