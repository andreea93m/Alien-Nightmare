//
// Created by sorin on 5/30/15.
//

#pragma once

#include <GL/glu.h>

namespace AlienNightmare {
    struct Position {
	    GLfloat x, y, z;

	    Position() : x(0), y(0), z(0) { };

	    Position(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) { };
    };

    struct Size {
	    GLfloat width, height, depth;

	    Size() : width(0), height(0), depth(0) { };

	    Size(GLfloat width, GLfloat height, GLfloat depth) : width(width), height(height), depth(depth) { }
    };
}
