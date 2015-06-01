//
// Created by sorin on 5/30/15.
//

#include "../include/Scene.h"

AlienNightmare::Scene::Scene(Position position, Size size) : Object(position, size) { }

void AlienNightmare::Scene::drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glPushMatrix();
	{
		glRotatef(90, 1, 0, 0);
		glColor4f(red, green, blue, alpha);
		glRectf(0, 0, size.width, size.height);
	}
	glPopMatrix();
}

void AlienNightmare::Scene::drawWalls(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glPushMatrix();
	{
		// Draw left wall
		glPushMatrix();
		{
			glRotatef(90, 0, -1, 0);
			glColor4f(red, green, blue, alpha);
			glRectf(0, 0, size.width, size.height);
		}
		glPopMatrix();

		// Draw right wall
		glPushMatrix();
		{
			glRotatef(-90, 0, 1, 0);
			glTranslatef(0, 0, - size.width);
			glColor4f(red, green, blue, alpha);
			glRectf(0, 0, size.width, size.height);
		}
		glPopMatrix();

		// Draw back wall
		glPushMatrix();
		{
			glColor4f(red, green, blue, alpha);
			glRectf(0, 0, size.width, size.height);
		}
		glPopMatrix();

		// Draw roof wall
		glPushMatrix();
		{
			glTranslatef(0, size.height, 0);
			glRotatef(90, 1, 0, 0);
			glColor4f(red, green, blue, alpha);
			glRectf(0, 0, size.width, size.height);
		}
		glPopMatrix();
	}
	glPopMatrix();
}
