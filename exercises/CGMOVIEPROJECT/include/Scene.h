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

#include "GLhelpers.h"

#endif

namespace AlienNightmare {
    class Scene {
    public:


    protected:
	    const Size size;
	    const Position position;

	    void drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	    void drawDemo(float movieTime);

    public:
	    Scene(Position position, Size size);

	    virtual void render(float movieTime) = 0;
	    virtual void update() = 0;
    };
}
