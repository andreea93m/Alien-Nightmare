/*
 * Animal.h
 *
 *  Created on: Jun 18, 2015
 *      Author: andreea
 */

#pragma once

#include "include/Headers.h"
#include <oogl/Image.h>
#include <oogl/Texture.h>
#include <algorithm>
#include <string>
#include "Scene.h"
#include "Shader.h"
#include "Object.h"
#include "Parallelepiped.h"

namespace AlienNightmare {
    class Animal : public Object {
    private:
	    oogl::Texture *texture;
	    Parallelepiped body, leftFrontLeg, rightFrontLeg, leftBackLeg, rightBackLeg;

    public:
	    Animal(const AlienNightmare::Position &position, GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
