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

namespace AlienNightmare {
    class Scene {
    public:
	    struct Size {
		    GLfloat width, height, depth;
		    Size(GLfloat width, GLfloat height, GLfloat depth) : width(width), height(height), depth(depth) { }
	    };

	    struct Position {
		    GLfloat x, y, z;
		    Position(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) { }
	    };

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
