//
// Created by sorin on 6/2/15.
//

#include "../include/Sun.h"

AlienNightmare::Sun::Sun(const AlienNightmare::Position &position, const GLfloat radius) : Object(position, Size(2 * radius, 2 * radius, 2 * radius)) {
	color[0] = 1;
	color[1] = 1;
	color[3] = 0;
}

void AlienNightmare::Sun::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

		float ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
		float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
		float specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
		float lightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);

//		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, specular);

		//the light position is affected by the model view matrix, too
		glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);

		glDisable(GL_LIGHTING); //temporary disable lightning

		glColor3fv(color);
		glutSolidSphere(size.height / 2, 10, 10);

		glEnable(GL_LIGHTING);
	}
	glPopMatrix();
}

void AlienNightmare::Sun::update() {

}
