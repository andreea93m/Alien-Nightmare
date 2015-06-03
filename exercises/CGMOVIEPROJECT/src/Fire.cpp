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

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		for (int i = 0; i < particle.size(); i++) {
			particle[i].render(movieTime);
		}

		glDisable(GL_BLEND);
	}
	glPopMatrix();
}

void AlienNightmare::Fire::update() {
	for (int i = 0; i < particle.size(); i++) {
		particle[i].update();
	}
}
