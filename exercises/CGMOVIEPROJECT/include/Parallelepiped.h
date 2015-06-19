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
#include "Scene.h"

namespace AlienNightmare {
    class Parallelepiped : public Object {
    private:
	    Position initialPosition;
	    GLfloat speed, maxHeight, angle, direction;
		GLfloat rotationSpeed;
	    oogl::Texture *texture;

    public:
	    Parallelepiped(const AlienNightmare::Position &position, GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ, const std::string &filename);

	    void setJump(GLfloat speed, GLfloat height);

	    void setProperties(GLfloat angle, GLfloat direction);

	    virtual void render();

	    virtual void update(float delta);
    };
}
