//
// Created by sorin on 6/8/15.
//

#pragma once

#include <oogl/model/Model3ds.h>
#include <oogl/model/ModelObj.h>
#include "Object.h"
#include "Shader.h"

namespace AlienNightmare {
    class Alien : public Object {
    private:
	    oogl::model::ModelObj * model;
    public:
	    Alien(const Position &position, const Size &size);

	    virtual void render(float movieTime) override;

	    virtual void update() override;
    };
}
