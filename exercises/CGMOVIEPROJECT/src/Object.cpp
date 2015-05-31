//
// Created by sorin on 5/31/15.
//

#include "../include/Object.h"

void AlienNightmare::Object::drawCoordinateSystem() {
	glPushMatrix();
	{
		glBegin(GL_LINES);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(100, 0, 0);
		}
		glEnd();

		glBegin(GL_LINES);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(0, 100, 0);
		}
		glEnd();

		glBegin(GL_LINES);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 100);
		}
		glEnd();
	}
	glPopMatrix();
}

AlienNightmare::Object::Object(Position position, Size size) : position(position), size(size) { }

void AlienNightmare::Object::moveToPosition() {
	glTranslatef(position.x, position.y, position.z);
}
