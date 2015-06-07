//
// Created by sorin on 5/31/15.
//

#include "../include/Polandball.h"

AlienNightmare::Polandball::Polandball(GLfloat radius, GLfloat angle, const std::string & filename) :
		Object(Position(0, 0, 0), Size(radius, radius, radius)), initialPosition(position), angle(angle),
		quadric(gluNewQuadric()), speed(0.0f) {

	oogl::Image * image = oogl::loadImage(filename);

	// Allocate space for the texture
	glGenTextures(1, & textureId);

	// Set the texture to edit
	glBindTexture(GL_TEXTURE_2D, textureId);

	// Map the image to the texture
	glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGB,
			image->getWidth(),
			image->getHeight(),
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			image->getData()
	);

	glBindTexture(GL_TEXTURE_2D, 0);

	delete image;
}

void AlienNightmare::Polandball::render(float movieTime) {
	glPushMatrix();
	{
		position.y += movieTime * speed;

		moveToPosition();

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, textureId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Rotate the sphere such that the 'face' of the polandball is looking at the camera
		glRotatef(90, 1, 0, 0);
		glRotatef(180, 0, 1, 0);
		glRotatef(180 + angle, 0, 0, 1);

		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, size.width / 2, 10, 10);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();
}

void AlienNightmare::Polandball::update() {
	if(speed && (position.y - initialPosition.y + size.height / 2 > maxHeight || position.y - initialPosition.y - size.height / 2 < 0)) {
		printf("switch: position.y = %lf\n", position.y);
		speed = -speed;
	}
}

void AlienNightmare::Polandball::setJump(GLfloat speed, GLfloat height) {
	this->speed = speed;
	this->maxHeight = height;
}
