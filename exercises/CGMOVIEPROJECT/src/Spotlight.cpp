//
// Created by sorin on 6/7/15.
//

#include "../include/Spotlight.h"

AlienNightmare::Spotlight::Spotlight(const AlienNightmare::Position &position, const AlienNightmare::Size &size) : Object(position, size) { }

void AlienNightmare::Spotlight::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		drawCoordinateSystem();

		GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
		GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
		GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat light_position[] = { size.width / 2, size.height / 2, size.depth / 2, 1.0 };

		GLfloat spot_pos[] = { 0.0, 0.0, 0.0, 1.0 };
		GLfloat spot_dir[] = { 0.0, -1.0 , 0.0 };
		glLightfv(GL_LIGHT3, GL_POSITION, spot_pos);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 45.0);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_dir);

		glLightfv(GL_LIGHT3, GL_POSITION, light_position);
		glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);
		glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.01f);

		glEnable(GL_LIGHT3);
	}
	glPopMatrix();
}

void AlienNightmare::Spotlight::update() {

}
