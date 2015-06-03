//
// Created by sorin on 5/30/15.
//

#include "../include/Scene.h"

AlienNightmare::Scene::Scene(Position position, Size size) : Object(position, size) { }

void AlienNightmare::Scene::drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glPushMatrix();
	{
		glColor3f(red, green, blue);

		//Bottom
		glBegin(GL_QUADS);
		{
			glNormal3f(0, 1, 0);
			glVertex3f(size.width, 0, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, size.depth);
			glVertex3f(size.width, 0, size.depth);
		}
		glEnd();
	}
	glPopMatrix();
}

void AlienNightmare::Scene::drawWalls(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glPushMatrix();
	{
		glColor3f(red, green, blue);

		// Back
		glBegin(GL_QUADS);
		{
			glNormal3f(0, -1, 0);
			glVertex3f(size.width, size.height, size.depth);
			glVertex3f(0, size.height, size.depth);
			glVertex3f(0, size.height, 0);
			glVertex3f(size.width, size.height, 0);
		}
		glEnd();

		// Back
		glBegin(GL_QUADS);
		{
			glNormal3f(0, 0, 1);
			glVertex3f(size.width, size.height, 0);
			glVertex3f(0, size.height, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(size.width, 0, 0);
		}
		glEnd();

		//Left
		glBegin(GL_QUADS);
		{
			glNormal3f(1, 0, 0);
			glVertex3f(0, size.height, 0);
			glVertex3f(0, size.height, size.depth);
			glVertex3f(0, 0, size.depth);
			glVertex3f(0, 0, 0);
		}
		glEnd();

		//Right
		glBegin(GL_QUADS);
		{
			glNormal3f(1, 0, 0);
			glVertex3f(0, size.height, 0);
			glVertex3f(0, size.height, size.depth);
			glVertex3f(0, 0, size.depth);
			glVertex3f(0, 0, 0);
		}
		glEnd();

		//Right
		glBegin(GL_QUADS);
		{
			glNormal3f(-1, 0, 0);
			glVertex3f(size.width, size.height, size.depth);
			glVertex3f(size.width, size.height, 0);
			glVertex3f(size.width, 0, 0);
			glVertex3f(size.width, 0, size.depth);
		}
		glEnd();
	}
	glPopMatrix();
}
