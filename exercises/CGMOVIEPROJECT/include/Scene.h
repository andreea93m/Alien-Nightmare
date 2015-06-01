//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Object.h"

namespace AlienNightmare {
    class Scene : public Object {
    protected:
	    Scene(Position position, Size size);

	    void drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	    void drawWalls(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    };
}
