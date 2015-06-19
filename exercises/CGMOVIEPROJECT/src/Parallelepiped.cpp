/*
 * Parallelepiped.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: andreea
 */

#include <oogl/Texture.h>
#include "../include/Parallelepiped.h"
#include <iostream>

AlienNightmare::Parallelepiped::Parallelepiped(
		const AlienNightmare::Position &position, GLfloat sizeX, GLfloat sizeY,
		GLfloat sizeZ, const std::string &filename) :
		Object(position, Size(sizeX, sizeY, sizeZ)), initialPosition(position) {
	angle = 0.0f;
	speed = 0.0f;
	direction = 0.0f;
	rotationSpeed = 0.8;
	texture = oogl::loadTexture(filename);
}

void AlienNightmare::Parallelepiped::render() {
	glPushMatrix();
	{


		glRotatef(angle, 1, 0, 0);
		moveToPosition();
		texture->bind(50);
		Shader::enableTexture(50);

		static GLfloat n[6][3] = { { -1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 1.0,
				0.0, 0.0 }, { 0.0, -1.0, 0.0 }, { 0.0, 0.0, 1.0 }, { 0.0, 0.0,
				-1.0 } };

		static GLint faces[6][4] = { { 0, 1, 2, 3 }, { 3, 2, 6, 7 }, { 7, 6, 5,
				4 }, { 4, 5, 1, 0 }, { 5, 6, 2, 1 }, { 7, 4, 0, 3 } };

		GLfloat v[8][3];
		GLint i;

		v[0][0] = v[1][0] = v[2][0] = v[3][0] = -this->size.width / 2;
		v[4][0] = v[5][0] = v[6][0] = v[7][0] = this->size.width / 2;
		v[0][1] = v[1][1] = v[4][1] = v[5][1] = -this->size.height / 2;
		v[2][1] = v[3][1] = v[6][1] = v[7][1] = this->size.height / 2;
		v[0][2] = v[3][2] = v[4][2] = v[7][2] = -this->size.depth / 2;
		v[1][2] = v[2][2] = v[5][2] = v[6][2] = this->size.depth / 2;

		for (i = 5; i >= 0; i--) {
			glBegin (GL_POLYGON);
			glNormal3fv(&n[i][0]);
			glTexCoord2f(1.0, 1.0);

			glVertex3fv(&v[faces[i][0]][0]);
			glTexCoord2f(0.0, 1.0);

			glVertex3fv(&v[faces[i][1]][0]);
			glTexCoord2f(0.0, 0.0);

			glVertex3fv(&v[faces[i][2]][0]);
			glTexCoord2f(1.0, 0.0);

			glVertex3fv(&v[faces[i][3]][0]);
			glEnd();
		}
		Shader::disableTexture();
		texture->unbind();

	}
	glPopMatrix();
}

void AlienNightmare::Parallelepiped::setJump(GLfloat speed, GLfloat height) {
	this->speed = speed;
	this->maxHeight = height;
}

void AlienNightmare::Parallelepiped::update(float delta) {
	if (speed
			&& (position.y - initialPosition.y > maxHeight
					|| position.y - initialPosition.y < 0)) {
		speed = -speed;
	}
	position.y += speed;

	if (direction == 1) {
		if(angle > 30 || angle < -30)
			rotationSpeed = -rotationSpeed;
		angle += rotationSpeed * 10;
	}
	else if(direction == -1){
		if(angle > 30 || angle < -30)
			rotationSpeed = -rotationSpeed;
		angle += rotationSpeed * 10;
	}

}

void AlienNightmare::Parallelepiped::setProperties(GLfloat angle,
		GLfloat direction) {
	this->angle = angle;
	this->direction = direction;
}
