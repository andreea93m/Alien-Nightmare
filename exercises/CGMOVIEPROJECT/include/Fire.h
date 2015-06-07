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

	    GLfloat light_ambient[4];
	    GLfloat light_diffuse[4];
	    GLfloat light_specular[4];
	    GLfloat light_position[4];

    public:
	    const float slowdown;
	    const Position speed;

	    Fire(unsigned long count, const Position &position, const Size &size);

	    virtual void render(float movieTime);

	    virtual void update();

	    void generateParticlePosition(Particle *particle);
    };
}
