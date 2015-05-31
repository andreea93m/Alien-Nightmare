//
// Created by sorin on 5/31/15.
//

#pragma once

namespace AlienNightmare {
    class Object;
}

#include "GLhelpers.h"

namespace AlienNightmare {
    class Object {
    protected:
	    void moveToPosition();

    public:
	    Size size;
	    Position position;

	    static void drawCoordinateSystem();

	    Object(Position position, Size size);

	    virtual void render(float movieTime) = 0;

	    virtual void update() = 0;

	    void placeRelative(Object * object, GLfloat xp, GLfloat yp, GLfloat zp);
    };
}
