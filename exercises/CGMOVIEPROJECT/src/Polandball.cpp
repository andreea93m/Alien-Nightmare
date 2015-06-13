//
// Created by sorin on 5/31/15.
//

#include <oogl/Texture.h>
#include "../include/Polandball.h"

AlienNightmare::Polandball::Polandball(GLfloat radius, GLfloat angle, const std::string &filename) :
Object(Position(0, 0, 0), Size(radius, radius, radius)), initialPosition(position), angle(angle),
quadric(gluNewQuadric()), speed(0.0f), forward_speed(0.0f) {

	texture = oogl::loadTexture(filename);
	direction = -2;
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

	if(forward_speed != 0){
		// go in front
		if(direction == 1){
			position.z+=forward_speed;
			if(position.z + forward_speed > scene->size.depth - 1){
				angle = -90;
				direction = 0;
			}
		}
		// go left
		else if(direction == 0){
			position.x-=forward_speed;
			if(position.x - forward_speed < 1){
				angle = 180;
				direction = -1;
			}

		}
		// go back
		else if(direction == -1){
			position.z-=forward_speed;
			if(position.z - forward_speed < 1){
				angle = 90;
				direction = -2;
			}
		}
		// go right
		else if(direction == -2){
			position.x+=forward_speed;
			if(position.x + forward_speed > scene->size.width - 1){
				angle = 360;
				direction = 1;
			}
		}
	}

}

void AlienNightmare::Polandball::setJump(GLfloat speed, GLfloat height) {
	this->speed = speed;
	this->maxHeight = height;
}

void AlienNightmare::Polandball::setJumpForward(GLfloat forward_speed, Scene *scene) {
	this->forward_speed = forward_speed;
	this->scene = scene;
	angle = 90;

}
