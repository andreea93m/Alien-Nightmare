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
#include "Polandball.h"

#include "Parallelepiped.h"

namespace AlienNightmare {
	/**
	 * A composed model (body, four legs and a head)
	 * It can walk around the edges of a scene, move its legs and
	 * bound its head
	 */
    class Animal : public Object {
    private:
	    Position initialPosition;
	    oogl::Texture *texture;
	    GLfloat speed, maxHeight, walkingAngle, walkingSpeed, walkingDirection;
	    Scene *scene;
	    Parallelepiped body, leftFrontLeg, rightFrontLeg, leftBackLeg, rightBackLeg;
	    Polandball head;

    public:
	    Animal(const AlienNightmare::Position &position, GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ, Scene *scene);

	    virtual void render();

	    /**
	     * Configure the jumping and walking
	     */
	    void setJump(GLfloat speed, GLfloat height, GLfloat walkingSpeed);

	    virtual void update(float delta);
    };
}
