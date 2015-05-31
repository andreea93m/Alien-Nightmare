//
// Created by sorin on 5/31/15.
//

#pragma once

#if defined(__APPLE__) || defined(__APPLE_CC__)
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else

# include <GL/glu.h>	// OpenGL Utility header
# include <GL/glut.h>	// GLUT header

#endif

#include "Object.h"

namespace AlienNightmare {
    class DemoObject : public Object {

    public:
	    DemoObject(Position position, Size size);

	    void render(float movieTime);

	    void update();
    };
}
