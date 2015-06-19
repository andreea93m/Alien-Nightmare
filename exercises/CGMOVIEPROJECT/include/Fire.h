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

    class Fire : public Object {
    private:
	    std::default_random_engine generator;
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

	    virtual void update();

	    void generateParticlePosition(Particle *particle);
    };
}
