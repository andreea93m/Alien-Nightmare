/*
 * Bat.h
 *
 *  Created on: Jun 9, 2015
 *      Author: andreea
 */

#pragma once

#include "Headers.h"

#include <oogl/model/Model3ds.h>
#include <oogl/model/ModelObj.h>
#include <oogl/Texture.h>
#include "Object.h"
#include "Shader.h"

namespace AlienNightmare {
    class Bat : public Object {
    private:
	    oogl::model::Model3ds * model;
	    Position initialPosition;
	    GLfloat up;
	    GLfloat speed;
    public:
	    Bat(const Position &position, const Size &size);

	    virtual void render(float movieTime) override;

	    void setSpeed(GLfloat speed);

	    virtual void update() override;
    };
}
