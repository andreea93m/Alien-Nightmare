//
// Created by sorin on 6/3/15.
//

#pragma once

#include "Camera.h"

namespace AlienNightmare {
	// Forward declaration
    class Particle;
}

#include <algorithm>
#include "Object.h"
#include "Fire.h"

namespace AlienNightmare {
	/**
	 * Encapsulates the concept of a particle from a fire
	 * The particle is a billboard
	 */
    class Particle : public Object {
    private:
	    /**
	     * The fire it belongs to
	     */
	    Fire *fire;

	    /**
	     * The life of the particle
	     * It fades away as time passes
	     */
	    GLfloat life;

	    /**
	     * The opacity of the particles
	     * Fades away as time passes
	     */
	    GLfloat fade;

	    /**
	     * The direction the particle will move towards
	     */
	    Position direction;

	    /**
	     * Towards which direction the particle is pulled
	     */
	    Position gravity;

	    /**
	     * A particle is a square, these are the coordinates of the corners
	     */
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
