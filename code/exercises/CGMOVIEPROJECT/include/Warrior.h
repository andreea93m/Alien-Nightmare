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
#include "Scene.h"
#include "Shader.h"

namespace AlienNightmare {
	/**
	 * 3D model featuring a warrior robot
	 */
    class Warrior : public Object {
    private:
	    oogl::model::Model3ds *model;
	    Position initialPosition;
	    Scene *scene;
	    GLfloat direction;
	    GLfloat angle;
	    GLfloat speed;
    public:
	    Warrior(const Position &position, const Size &size, Scene *scene);

	    virtual void render() override;

	    void setSpeed(GLfloat speed);

	    virtual void update(float delta) override;
    };
}
