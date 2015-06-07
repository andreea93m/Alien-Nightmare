//
// Created by sorin on 6/3/15.
//

#pragma once

#include "Camera.h"

namespace AlienNightmare {
    class Particle;
}

#include <algorithm>
#include "Object.h"
#include "Fire.h"

namespace AlienNightmare {
    class Particle : public Object {
    private:
	    Fire *fire;
	    GLfloat life, fade;
	    Position direction, gravity;

	    float generate(float low, float high);

    public:
	    Particle(Fire *fire, GLfloat size);

	    virtual void update();

	    void render(float movieTime);
    };
}
