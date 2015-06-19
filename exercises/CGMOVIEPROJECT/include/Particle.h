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

	    glm::vec3 topRight;
	    glm::vec3 topLeft;
	    glm::vec3 bottomRight;
	    glm::vec3 bottomLeft;

	    float generate(float low, float high);

    public:
	    Particle(Fire *fire, GLfloat size);

	    virtual void update(float delta);

	    void render();
    };
}
