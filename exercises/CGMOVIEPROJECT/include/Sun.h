//
// Created by sorin on 6/2/15.
//

#pragma once

#include <oogl/glutIncludes.h>
#include "Object.h"

namespace AlienNightmare {
    class Sun : public Object {
    private:
	    GLfloat color[3];

    public:
	    Sun(const Position &position, const GLfloat radius);

	    virtual void render(float movieTime);
	    virtual void update();
    };
}
