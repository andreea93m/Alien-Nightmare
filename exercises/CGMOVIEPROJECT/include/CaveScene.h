//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"
#include "Fire.h"
#include "Polandball.h"
#include "Bat.h"

namespace AlienNightmare {
    class CaveScene : public Scene {
    public:
	    Polandball denmark, germany, poland;
	    Fire fire;
	    Bat bat;

    public:
	    CaveScene(Position position, Size size);

	    virtual void render();

	    virtual void update(float delta);
    };
}
