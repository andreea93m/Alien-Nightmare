#include "../include/Particle.h"

AlienNightmare::Particle::Particle(Fire *fire, GLfloat size) : Object(Position(fire, 0.5, 0, 0.5),
	Size(size, size, size)), fire(fire), fade(0.0),
                                                               gravity(0.0, 0.8, 0.0), life(-1) {
	update(0.0);
}

void AlienNightmare::Particle::render() {
	glPushMatrix();
	{
		moveToPosition();

		glColor4f(1.0, life, life / 4, life);

		glBegin(GL_TRIANGLE_STRIP);
		{
			topRight = glm::vec3(position.x + size.width, position.y + size.height, size.depth);
			topLeft = glm::vec3(position.x - size.width, position.y + size.height, size.depth);
			bottomRight = glm::vec3(position.x + size.width, position.y - size.height, size.depth);
			bottomLeft = glm::vec3(position.x - size.width, position.y - size.height, size.depth);

			topRight -= (Camera::right + Camera::up);
			topLeft += (Camera::right - Camera::up);
			bottomRight += (Camera::right + Camera::up);
			bottomLeft -= (Camera::right - Camera::up);

			topRight *= 0.1;
			topLeft *= 0.1;
			bottomRight *= 0.1;
			bottomLeft *= 0.1;

			glVertex3fv(&topRight.x);
			glVertex3fv(&topLeft.x);
			glVertex3fv(&bottomLeft.x);
			glVertex3fv(&bottomRight.x);
		}
		glEnd();

	}
	glPopMatrix();
}

void AlienNightmare::Particle::update(float delta) {
	position.x += direction.x / (fire->slowdown);
	position.y += direction.y / (fire->slowdown);
	position.z += direction.z / (fire->slowdown);

	direction.x += gravity.x;
	direction.y += gravity.y;
	direction.z += gravity.z;

	life -= fade;

	if (life < 0.0) {
		life = 1.0;

		fire->generateParticlePosition(this);
		fade = generate(0.01, 0.05);

		direction.x = fire->speed.x + generate(-5, 5);
		direction.y = 0.0f;
		direction.z = generate(-15, 15);
	}
}

float AlienNightmare::Particle::generate(float low, float high) {
	return low + rand() / (RAND_MAX / (high - low));
}
