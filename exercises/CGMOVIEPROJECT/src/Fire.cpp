//
// Created by sorin on 6/3/15.
//

#include "../include/Fire.h"

AlienNightmare::Fire::Fire(unsigned long count, const AlienNightmare::Position &position,
                           const AlienNightmare::Size &size)
		: Object(position, size), slowdown(0.000003),
		  xNormalDistribution(0, (float) (size.width / 2.0)), zNormalDistribution(0, size.depth / 2.0),
		  light_ambient({0.0, 0.0, 0.0, 1.0}), light_diffuse({1.0, 1.0, 0.0, 1.0}),
		  light_specular({1.0, 1.0, 1.0, 1.0}), light_position({size.width / 2, size.height / 2, size.depth / 2, 1.0}) {

	for (int i = 0; i < count; ++i) {
		particle.push_back(Particle(this, 0.05));
	}
}

void AlienNightmare::Fire::render() {
	glPushMatrix();
	{
		moveToPosition();

		glLightfv(GL_LIGHT2, GL_POSITION, &light_position[0]);
		glLightfv(GL_LIGHT2, GL_AMBIENT, &light_ambient[0]);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, &light_diffuse[0]);
		glLightfv(GL_LIGHT2, GL_SPECULAR, &light_specular[0]);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.1f);

		glEnable(GL_LIGHT2);

		Shader::enableLight(2);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		for (int i = 0; i < particle.size(); i++) {
			particle[i].render();
		}

		glDisable(GL_BLEND);
	}
	glPopMatrix();
}

void AlienNightmare::Fire::update(float delta) {
	for (int i = 0; i < particle.size(); i++) {
		particle[i].update(delta);
	}
}

void AlienNightmare::Fire::generateParticlePosition(AlienNightmare::Particle *particle) {
	GLfloat xDelta = size.width;
	GLfloat zDelta = size.depth;

	while (xDelta < -size.width / 2.0f || size.width / 2.0f < xDelta) {
		xDelta = xNormalDistribution(generator);
	}

	while (zDelta < -size.depth / 2.0f || size.depth / 2.0f < zDelta) {
		zDelta = zNormalDistribution(generator);
	}

	particle->position.x = size.width / 2.0f + xDelta;
	particle->position.y = 0.0f;
	particle->position.z = size.depth / 2.0f + zDelta;
}
