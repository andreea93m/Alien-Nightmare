//
// Created by sorin on 5/31/15.
//

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
    class Polandball : public Object {
    private:
	    Position initialPosition;
	    GLUquadric *quadric;
	    Scene *scene;
	    GLfloat direction;
	    GLfloat angle;
	    GLfloat speed, maxHeight, forward_speed;
	    oogl::Texture *texture;
		bool isSpecular;

    public:
	    Polandball(GLfloat radius, GLfloat angle, const std::string &fileName);

	    void setJump(GLfloat speed, GLfloat height);

	    void setJumpForward(GLfloat speed, Scene *scene);

	    virtual void render();

	    virtual void update(float delta);
    };
}
