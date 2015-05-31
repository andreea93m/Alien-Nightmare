//
// Created by sorin on 5/30/15.
//

#pragma once

#include <GLee.h>

#if defined(__APPLE__) || defined(__APPLE_CC__)
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else

# include <GL/gl.h>		// OpenGL header
# include <GL/glu.h>	// OpenGL Utility header
# include <GL/glut.h>	// GLUT header

#endif

#include "Object.h"

namespace AlienNightmare {
    class Scene : public Object {
    protected:
	    Scene(Position position, Size size);

	    void drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	    void drawDemo(float movieTime);
    };
}
