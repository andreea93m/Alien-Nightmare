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

void AlienNightmare::Scene::drawDemo(float movieTime) {
	glPushMatrix();
	{
		glTranslatef(size.width / 2, size.height / 2, -size.depth / 2);
		glRotatef(movieTime * 0.05f, 0, 1, 0);

		//       v3
		//        *
		//       / \
		//      /   \
		//     /     \
		// v1 *-------* v2

		glBegin(GL_TRIANGLES);
		{
			//v1
			glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
			glVertex3f(-1, -1.0f, 0);

			//v2
			glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
			glVertex3f(1, -1.0f, 0);

			//v3
			glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
			glVertex3f(0, 1, 0);
		}
		glEnd();


		// top cube
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glPushMatrix();
		{
			glTranslatef(0, 1, 0);
			glutSolidCube(0.25);
		}
		glPopMatrix();


		// left cube
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glPushMatrix();
		{
			glTranslatef(-1.0f, -1.0f, 0);
			glutSolidCube(0.25);
		}
		glPopMatrix();


		// right cube
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glPushMatrix();
		{
			glTranslatef(1.0f, -1.0f, 0);
			glutSolidCube(0.25);
		}
		glPopMatrix();
	}
	glPopMatrix();
}
