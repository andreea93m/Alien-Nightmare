//
// Created by sorin on 5/30/15.
//

#pragma once

#include "include/Headers.h"
#include <glm/glm.hpp>

namespace AlienNightmare {
	// Forward declaration
    class Object;

	/**
	 * Encapsulates the concept of position
	 */
    class Position {
    public:
	    GLfloat x, y, z;

	    Position();

	    Position(GLfloat x, GLfloat y, GLfloat z);

	    Position(Object *object, GLfloat xp, GLfloat yp, GLfloat zp);
    };

	/**
	 * Encapsulates the concept of size
	 */
    class Size {
    public:
	    GLfloat width, height, depth;

	    Size();

	    Size(GLfloat width, GLfloat height, GLfloat depth);
    };
}
