//
// Created by sorin on 6/6/15.
//

#pragma once

#include "include/Headers.h"
#include <iostream>
#include <math.h>
#include "Scene.h"
#define _USE_MATH_DEFINES

#define M_PI 3.1456867

#include <cmath>
#include <glm/glm.hpp>



namespace AlienNightmare {
    class Camera {
    private:
	    static const GLfloat mouseSensitivity;

	    static GLfloat speed;
	    static GLfloat animateSpeed;
	    static GLfloat moveX, moveZ;

	    static float horizontalAngle;
	    static float verticalAngle;

    public:
	    static glm::vec3 eye, center, right, up;

	    static void mouseMove(int dx, int dy);
	    static void move(float directionX, float directionZ, float speed);
	    static void update(float delta);
	    static float distanceTo(Scene *scene);
	    static void keyboardDown(int key);

	    static void keyboardUp(int key);

	    static void setViewMatrix();
    };
}
