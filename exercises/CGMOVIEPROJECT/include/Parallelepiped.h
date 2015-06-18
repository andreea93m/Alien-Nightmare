/*
 * Parallelepiped.h
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

namespace AlienNightmare {
    class Parallelepiped : public Object {
    private:
	    Position initialPosition;
	    oogl::Texture *texture;

    public:
	    Parallelepiped(GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
