//
// Created by sorin on 5/30/15.
//

#pragma once

#include <gl.h>
#include <glm/glm.hpp>

namespace AlienNightmare {
    class Object;

    class Position : public glm::vec3 {
    public:
	    GLfloat x, y, z;

	    Position();

	    Position(GLfloat x, GLfloat y, GLfloat z);

	    Position(Object *object, GLfloat xp, GLfloat yp, GLfloat zp);
    };

    class Size {
    public:
	    GLfloat width, height, depth;

	    Size();

	    Size(GLfloat width, GLfloat height, GLfloat depth);
    };
}
