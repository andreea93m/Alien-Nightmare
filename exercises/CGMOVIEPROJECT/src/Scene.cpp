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
