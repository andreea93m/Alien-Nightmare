//
// Created by sorin on 5/31/15.
//

#include "../include/DemoObject.h"

AlienNightmare::DemoObject::DemoObject(Position position, Size size) : Object(position, size) { }

void AlienNightmare::DemoObject::render() {
	glPushMatrix();
	{
		moveToPosition();
//		glRotatef(movieTime * 0.05f, 0, 1, 0);

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

void AlienNightmare::DemoObject::update() {

}
