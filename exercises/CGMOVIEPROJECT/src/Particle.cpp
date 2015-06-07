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

		GLfloat ambient[] = { 1.0, life, life / 4, life };
		GLfloat diffuse[] = { 1.0, life, life / 4, life };
		GLfloat specular[] = { 1.0, life, life / 4, life };
		GLfloat shininess = 32.0; // [0..128]

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);

		glColor4f(1.0, life, life / 4, life);

		glBegin(GL_TRIANGLE_STRIP);
		{
			glm::vec3 topRight = glm::vec3(position.x + size.width, position.y + size.height, size.depth);
			glm::vec3 topLeft = glm::vec3(position.x - size.width, position.y + size.height, size.depth);
			glm::vec3 bottomRight = glm::vec3(position.x + size.width, position.y - size.height, size.depth);
			glm::vec3 bottomLeft = glm::vec3(position.x - size.width, position.y - size.height, size.depth);

			topRight -= (Camera::right + Camera::up);
			topLeft += (Camera::right - Camera::up);
			bottomRight += (Camera::right + Camera::up);
			bottomLeft -= (Camera::right - Camera::up);

			topRight *= 0.1;
			topLeft *= 0.1;
			bottomRight *= 0.1;
			bottomLeft *= 0.1;

			glVertex3fv(& topRight.x);
			glVertex3fv(& topLeft.x);
			glVertex3fv(& bottomLeft.x);
			glVertex3fv(& bottomRight.x);
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
