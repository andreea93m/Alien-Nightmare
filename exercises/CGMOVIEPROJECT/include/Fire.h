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
    public:
	    unsigned long count;
	    float slowdown;
	    Position speed;
	    GLuint textureId;

	    std::default_random_engine generator;
	    std::normal_distribution<double> xdist, zdist;

	    std::vector<Particle> particle;            // Particle Array (Room For Particle Info)

    public:
	    Fire(unsigned long count, const Position &position, const Size &size);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
