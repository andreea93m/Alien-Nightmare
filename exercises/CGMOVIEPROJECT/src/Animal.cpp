/*
 * Animal.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: andreea
 */

#include <oogl/Texture.h>
#include "../include/Animal.h"

AlienNightmare::Animal::Animal(
		const AlienNightmare::Position &position, GLfloat sizeX, GLfloat sizeY,
		GLfloat sizeZ) :
		Object(position, Size(sizeX, sizeY, sizeZ)), body(position, sizeX, sizeY, sizeZ),
		leftFrontLeg(Position(this, 4.5, 4.3, 5.25), 0.5,0.5,0.5),
		rightFrontLeg(Position(this, 5.5, 4.3, 5.25), 0.5,0.5,0.5),
		leftBackLeg(Position(this, 4.5, 4.3, 4.75), 0.5,0.5,0.5),
		rightBackLeg(Position(this, 5.5, 4.3, 4.75), 0.5,0.5,0.5),
		initialPosition(position)
 {
	speed = 0.0f;
}

void AlienNightmare::Animal::render(float movieTime) {
	body.render(movieTime);
	leftFrontLeg.render(movieTime);
	rightFrontLeg.render(movieTime);
	leftBackLeg.render(movieTime);
	rightBackLeg.render(movieTime);

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
