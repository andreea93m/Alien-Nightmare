//
// Created by sorin on 6/6/15.
//

#pragma once

#if defined(__APPLE__) || defined(__APPLE_CC__)
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else

# include <GL/glu.h>	// OpenGL Utility header
# include <GL/glut.h>	// GLUT header

#endif

#include <cmath>
#include <glm/glm.hpp>

namespace AlienNightmare {
    class Camera {
    private:
	    static const GLfloat mouseSensitivity;

	    static GLfloat speed;
	    static GLfloat moveX, moveZ;

	    static float horizontalAngle;
	    static float verticalAngle;

    public:
	    static glm::vec3 eye, center, right, up;

	    static void mouseMove(int dx, int dy);

	    static void update(float delta);

	    static void keyboardDown(int key);

	    static void keyboardUp(int key);

	    static void setViewMatrix();
    };
}
