//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"
#include "Fire.h"
#include "Polandball.h"
#include "Bat.h"
#include "Alien.h"

namespace AlienNightmare {
	/**
	 * The first scene.
	 * Consists of a three polandballs around a fire, in a cave.
	 * An alien is lurking in the corner, and a bat hangs around over the fire
	 */
    class CaveScene : public Scene {
    public:
	    Polandball denmark, germany, poland;
	    Fire fire;
	    Alien alien;
	    Bat bat;

    public:
	    CaveScene(Position position, Size size);

	    virtual void render();

	    virtual void update(float delta);
    };
}
