/*
 * Warrior.h
 *
 *  Created on: Jun 9, 2015
 *      Author: andreea
 */

#pragma once

#include <oogl/model/Model3ds.h>
#include <oogl/model/ModelObj.h>
#include <oogl/Texture.h>
#include "Object.h"
#include "Shader.h"

namespace AlienNightmare {
    class Warrior : public Object {
    private:
	    oogl::model::Model3ds * model;
    public:
	    Warrior(const Position &position, const Size &size);

	    virtual void render(float movieTime) override;

	    virtual void update() override;
    };
}
