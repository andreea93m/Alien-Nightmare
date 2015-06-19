//
// Created by sorin on 5/30/15.
//

#pragma once

#include "include/Headers.h"
#include "Object.h"
#include "Shader.h"
#include <oogl/Texture.h>

namespace AlienNightmare {
	/**
	 * Encapsulates the concept of a scene
	 * Provides helper methods to draw the walls and the floor
	 */
    class Scene : public Object {
    private:
	    oogl::Texture *texture;
	    oogl::Texture *texture1;
    protected:
	    Scene(Position position, Size size);

	    void drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	    void drawWalls(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    };
}
