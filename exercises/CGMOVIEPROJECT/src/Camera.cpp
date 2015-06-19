//
// Created by sorin on 6/6/15.
//

#include "../include/Camera.h"

const GLfloat AlienNightmare::Camera::mouseSensitivity = 0.005f;
glm::vec3 AlienNightmare::Camera::eye, AlienNightmare::Camera::center, AlienNightmare::Camera::right, AlienNightmare::Camera::up;

GLfloat AlienNightmare::Camera::speed = 0.05;
GLfloat AlienNightmare::Camera::moveX, AlienNightmare::Camera::moveZ;

GLfloat AlienNightmare::Camera::horizontalAngle = (GLfloat) M_PI;
float AlienNightmare::Camera::verticalAngle;

void AlienNightmare::Camera::update(float delta) {
	Camera::center = glm::vec3(
			cos(Camera::verticalAngle) * sin(Camera::horizontalAngle),
			sin(Camera::verticalAngle),
			cos(Camera::verticalAngle) * cos(Camera::horizontalAngle)
	);

	Camera::right = glm::vec3(
			sin(Camera::horizontalAngle - M_PI / 2.0),
			0,
			cos(Camera::horizontalAngle - M_PI / 2.0)
	);

	Camera::up = glm::cross(Camera::right, Camera::center);

	Camera::eye += Camera::center * delta * Camera::moveZ;
	Camera::eye += Camera::right * delta * Camera::moveX;

}

void AlienNightmare::Camera::keyboardDown(int key) {
	Camera::moveX = (key == GLUT_KEY_RIGHT) ? speed : (key == GLUT_KEY_LEFT) ? -speed : 0;
	Camera::moveZ = (key == GLUT_KEY_UP) ? speed : (key == GLUT_KEY_DOWN) ? -speed : 0;
}

void AlienNightmare::Camera::keyboardUp(int key) {
	Camera::moveX = (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT) ? 0 : Camera::moveX;
	Camera::moveZ = (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) ? 0 : Camera::moveZ;

}

/**
 * Move camera along x or z axis according to a speed
 * used for animated camera flight
 */

void AlienNightmare::Camera::move(float directionX, float directionZ, float speed) {
	Camera::moveX = directionX * speed;
	Camera::moveZ = directionZ * speed;
}

void AlienNightmare::Camera::mouseMove(int dx, int dy) {
	Camera::horizontalAngle += mouseSensitivity * dx;
	Camera::verticalAngle += mouseSensitivity * dy;
}

void AlienNightmare::Camera::setViewMatrix() {
	gluLookAt(Camera::eye.x, Camera::eye.y, Camera::eye.z,
	          Camera::eye.x + Camera::center.x,
	          Camera::eye.y + Camera::center.y,
	          Camera::eye.z + Camera::center.z,
	          Camera::up.x, Camera::up.y, Camera::up.z
	);
}

void AlienNightmare::Camera::reset() {
	Camera::eye.x = 0;
	Camera::eye.y = 5;
	Camera::eye.z = 65;
	Camera::center.x = 0;
	Camera::center.y = 0;
	Camera::center.z = -1;
	Camera::right.x = 0;
	Camera::right.y = 0;
	Camera::right.z = 0;
	Camera::up.x = 0;
	Camera::up.y = 1;
	Camera::up.z = 0;
	Camera::moveX = 0;
	Camera::moveZ = 0;
	Camera::horizontalAngle = (GLfloat) M_PI;
	//Camera::horizontalAngle = 0;
	Camera::verticalAngle = 0;
	Camera::speed = 0.05;
}

/**
 * Compute Euclidean distance from camera to scene to know
 * when to start updating the scenes during free camera mode
 */

float AlienNightmare::Camera::distanceTo(Scene *scene) {
	return sqrt((scene->position.x - Camera::eye.x) * (scene->position.x - Camera::eye.x) +
	            (scene->position.y - Camera::eye.y) * (scene->position.y - Camera::eye.y) +
	            (scene->position.z - Camera::eye.z) * (scene->position.z - Camera::eye.z));
}
