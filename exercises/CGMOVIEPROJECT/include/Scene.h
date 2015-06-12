//
// Created by sorin on 5/30/15.
//

#pragma once
#include "include/Headers.h"
#include "Object.h"
#include "Shader.h"
#include <oogl/Texture.h>

namespace AlienNightmare {
    class Scene : public Object {
    private:
	    oogl::Texture *texture;
    protected:
	    Scene(Position position, Size size);

	    void drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	    void drawWalls(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    };
}
