//
// Created by sorin on 5/31/15.
//

#include <oogl/Texture.h>
#include "../include/Polandball.h"

AlienNightmare::Polandball::Polandball(GLfloat radius, GLfloat angle, const std::string &filename) :
		Object(Position(0, 0, 0), Size(radius, radius, radius)), initialPosition(position), angle(angle),
		quadric(gluNewQuadric()), speed(0.0f) {

	texture = oogl::loadTexture(filename);
}

void AlienNightmare::Polandball::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

		texture->bind(5);
		Shader::enableTexture(5);

		// Rotate the sphere such that the 'face' of the polandball is looking at the camera
		glRotatef(90, 1, 0, 0);
		glRotatef(180, 0, 1, 0);
		glRotatef(180 + angle, 0, 0, 1);

		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, size.width / 2, 10, 10);

		Shader::disableTexture();
		texture->unbind();
	}
	glPopMatrix();
}

void AlienNightmare::Polandball::update() {
	if (speed && (position.y - initialPosition.y + size.height / 2 > maxHeight ||
	              position.y - initialPosition.y - size.height / 2 < 0)) {
		speed = -speed;
	}

	position.y += speed;
}

void AlienNightmare::Polandball::setJump(GLfloat speed, GLfloat height) {
	this->speed = speed;
	this->maxHeight = height;
}
