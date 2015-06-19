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
	/**
	 * Encapsulates the camera concept in OpenGL
	 * Provides helpful methods to move it around the world
	 * with mouse movements and keyboard keys.
	 */
    class Camera {
    private:
	    static const GLfloat mouseSensitivity;

	    static GLfloat speed;
	    static GLfloat moveX, moveZ;

	    static float horizontalAngle;
	    static float verticalAngle;

    public:
	    static glm::vec3 eye, center, right, up;

	    /**
	     * Handles a mouse move
	     * dx - change in x coordinates
	     * dy - change in y coordinates
	     */
	    static void mouseMove(int dx, int dy);

	    /**
	     * Moves the camera along the specified directions with a given speed
	     */
	    static void move(float directionX, float directionZ, float speed);

	    static void update(float delta);

	    /**
	     * Computes the euclidean distance to the given scene
	     * Useful for detecting when we are close enough to trigger the animations
	     */
	    static float distanceTo(Scene *scene);

	    /**
	     * Handles a keyboard down event
	     * key - a GLUT key code
	     */
	    static void keyboardDown(int key);

	    /**
	     * Takes the camera back where it was when the program started
	     */
	    static void reset();

	    /**
	     * Handles a keyboard up event
	     * key - a GLUT key code
	     */
	    static void keyboardUp(int key);

	    /**
	     * Sets the view matrix using gluLookAt
	     */
	    static void setViewMatrix();
    };
}
