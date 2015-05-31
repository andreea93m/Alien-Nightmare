//
// Created by sorin on 5/31/15.
//

#pragma once

#include "GLhelpers.h"

namespace AlienNightmare {
    class Object {
    protected:
	    const Size size;
	    const Position position;

	    void moveToPosition();

    public:
	    Object(Position position, Size size);

	    virtual void render(float movieTime) = 0;
	    virtual void update() = 0;
    };
}
