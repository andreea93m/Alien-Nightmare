//
// Created by sorin on 6/3/15.
//

#include "../include/Fire.h"

AlienNightmare::Fire::Fire(unsigned long count, const AlienNightmare::Position &position,
                           const AlienNightmare::Size &size)
		: Object(position, size), count(count), slowdown(2.0),
		  xdist(0, size.width / 2), zdist(0, size.depth / 2) {

	for (int i = 0; i < count; ++i) {
		particle.push_back(Particle(this, 0.05));
	}
}

void AlienNightmare::Fire::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

		GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
		GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
		GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat light_position[] = { size.width / 2, size.height / 2, size.depth / 2, 1.0 };

		light_position[0] += rand() % 1;
		light_position[1] += rand() % 1;
		light_position[2] += rand() % 1;

		glLightfv(GL_LIGHT2, GL_POSITION, light_position);
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01f);

		glEnable(GL_LIGHT2);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

//		Shader::usePhongShaderWithBillboarding();

		for (int i = 0; i < particle.size(); i++) {
			particle[i].render(movieTime);
		}

//		Shader::undoShaderChange();

		glDisable(GL_BLEND);
	}
	glPopMatrix();
}

void AlienNightmare::Fire::update() {
	for (int i = 0; i < particle.size(); i++) {
		particle[i].update();
	}
}
