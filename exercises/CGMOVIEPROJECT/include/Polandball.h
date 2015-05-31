//
// Created by sorin on 5/31/15.
//

#pragma once

#include <GLee.h>
#include <glu.h>
#include <oogl/Image.h>
#include <algorithm>
#include <string>
#include "Object.h"

namespace AlienNightmare {
    class Polandball : public Object {
    private:
	    GLUquadric * quadric;
	    GLuint textureId;

    public:
	    Polandball(GLfloat radius, const std::string & fileName);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
