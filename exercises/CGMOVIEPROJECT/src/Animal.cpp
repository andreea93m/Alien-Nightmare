/*
 * Animal.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: andreea
 */

#include <oogl/Texture.h>
#include "../include/Animal.h"

AlienNightmare::Animal::Animal(const AlienNightmare::Position &position,
		GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ) :
		Object(position, Size(sizeX, sizeY, sizeZ)), body(Position(0, 0, 0),
				sizeX, sizeY, sizeZ),
//		leftFrontLeg(Position(this, 4.5, 4.3, 5.25), 0.5,1,0.2),
//		rightFrontLeg(Position(this, 5.5, 4.3, 5.25), 0.5,1,0.2),
//		leftBackLeg(Position(this, 4.5, 4.3, 4.75), 0.5,1,0.2),
//		rightBackLeg(Position(this, 5.5, 4.3, 4.75), 0.5,1,0.2),
				leftFrontLeg(Position(&body, -0.4, -0.8, 0.3), 0.1, 1, 0.2), rightFrontLeg(
				Position(&body, 0.4, -0.8, 0.2), 0.1, 1, 0.3), leftBackLeg(
				Position(&body, -0.4, -0.8, -0.3), 0.1, 1, 0.2), rightBackLeg(
				Position(&body, 0.4, -0.8, -0.3), 0.1, 1, 0.2), initialPosition(
				position) {

	speed = 0.0f;
	leftFrontLeg.setProperties(-30, -1);
	leftBackLeg.setProperties(30, 1);
	rightBackLeg.setProperties(30, 1);
	rightFrontLeg.setProperties(-30, -1);
}

void AlienNightmare::Animal::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		body.render(movieTime);
		leftFrontLeg.render(movieTime);
		rightFrontLeg.render(movieTime);
		leftBackLeg.render(movieTime);
		rightBackLeg.render(movieTime);

	}
	glPopMatrix();
}

void AlienNightmare::Animal::setJump(GLfloat speed, GLfloat height) {
	this->speed = speed;
	this->maxHeight = height;
	body.setJump(speed, height);
	leftBackLeg.setJump(speed, height);
	rightBackLeg.setJump(speed, height);
	leftFrontLeg.setJump(speed, height);
	rightFrontLeg.setJump(speed, height);

}

void AlienNightmare::Animal::update() {
	body.update();
	leftBackLeg.update();
	rightBackLeg.update();
	leftFrontLeg.update();
	rightFrontLeg.update();

}
