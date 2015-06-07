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
	    Position initialPosition;
	    GLUquadric * quadric;
	    GLuint textureId;
	    GLfloat angle;
	    GLfloat speed, maxHeight;

    public:
	    Polandball(GLfloat radius, GLfloat angle, const std::string & fileName);

	    void setJump(GLfloat speed, GLfloat height);

	    virtual void render(float movieTime);
	    virtual void update();
    };
}
