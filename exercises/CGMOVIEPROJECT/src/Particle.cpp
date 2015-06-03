#include "../include/Particle.h"

AlienNightmare::Particle::Particle(Fire *fire, GLfloat size) : Object(Position(fire, 0.5, 0, 0.5),
                                                                      Size(size, size, size)), fire(fire),
                                                               gravity(0.0, 0.8, 0.0), life(-1) {
	update();
}

void AlienNightmare::Particle::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

		glColor4f(1.0, life, life / 4, life);

		glBegin(GL_TRIANGLE_STRIP);
		{
			glTexCoord2d(1, 1);
			glVertex3f(position.x + size.width, position.y + size.height, size.depth);
			glTexCoord2d(0, 1);
			glVertex3f(position.x - size.width, position.y + size.height, size.depth);
			glTexCoord2d(1, 0);
			glVertex3f(position.x + size.width, position.y - size.height, size.depth);
			glTexCoord2d(0, 0);
			glVertex3f(position.x - size.width, position.y - size.height, size.depth);
		}
		glEnd();

	}
	glPopMatrix();
}

void AlienNightmare::Particle::update() {
	position.x += direction.x / (1000 * fire->slowdown);
	position.y += direction.y / (1000 * fire->slowdown);
	position.z += direction.z / (1000 * fire->slowdown);

	direction.x += gravity.x;
	direction.y += gravity.y;
	direction.z += gravity.z;

	life -= fade;

	if (life < 0.0) {
		life = 1.0;

		Position p = Position(fire, 0.5, 0, 0.5);
		position.x = position.y = position.z = 100;

		while (position.x < 0 || fire->size.width < position.x) {
			position.x = p.x + fire->xdist(fire->generator);
		}

		position.y = 0;

		while (position.z < 0 || fire->size.depth < position.z) {
			position.z = p.z + fire->zdist(fire->generator);
		}

		fade = generate(0.01, 0.05);

		direction.x = fire->speed.x + generate(-5, 5);
		direction.y = 0.0f;
		direction.z = generate(-15, 15);
	}
}

float AlienNightmare::Particle::generate(float low, float high) {
	return low + rand() / (RAND_MAX / (high - low));
}
