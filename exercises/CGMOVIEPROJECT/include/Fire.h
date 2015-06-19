//
// Created by sorin on 6/3/15.
//

#pragma once

namespace AlienNightmare {
    class Fire;
}

#include <vector>
#include <random>
#include <oogl/Image.h>
#include "Shader.h"
#include "Object.h"
#include "Particle.h"

namespace AlienNightmare {

	/**
	 * A particle system simulating a fire
	 */
    class Fire : public Object {
    private:
	    std::default_random_engine generator;

	    /**
	     * The particles are normally generated along the X and Z axis, such
	     * that the flames are more intense around the center
	     * A light source is places among the particles which slowly moves in
	     * a random manner
	     */
	    std::normal_distribution<GLfloat> xNormalDistribution, zNormalDistribution;

	    std::vector<Particle> particle;

	    std::vector<GLfloat> light_ambient;
	    std::vector<GLfloat> light_diffuse;
	    std::vector<GLfloat> light_specular;
	    std::vector<GLfloat> light_position;

    public:
	    const float slowdown;
	    const Position speed;

	    Fire(unsigned long count, const Position &position, const Size &size);

	    virtual void render();

	    virtual void update(float delta);

	    /**
	     * Takes a particle and reinitializes its fields acording to the normal distributions
	     */
	    void generateParticlePosition(Particle *particle);
    };
}
