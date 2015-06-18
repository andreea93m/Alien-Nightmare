/*
 * Parallelepiped.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: andreea
 */

#include <oogl/Texture.h>
#include "../include/Parallelepiped.h"

AlienNightmare::Parallelepiped::Parallelepiped(GLfloat sizeX, GLfloat sizeY,
		GLfloat sizeZ) :
		Object(Position(0, 0, 0), Size(sizeX, sizeY, sizeZ)) {
}

void AlienNightmare::Parallelepiped::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

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
			glVertex3fv(&v[faces[i][0]][0]);
			glVertex3fv(&v[faces[i][1]][0]);
			glVertex3fv(&v[faces[i][2]][0]);
			glVertex3fv(&v[faces[i][3]][0]);
			glEnd();
		}
	}
	glPopMatrix();
}

void AlienNightmare::Parallelepiped::update(){

}

