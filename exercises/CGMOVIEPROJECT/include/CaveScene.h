//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"
#include "Fire.h"
#include "Sun.h"
#include "Polandball.h"

namespace AlienNightmare {
    class CaveScene : public Scene {
    public:
	    Sun sun;
	    Polandball denmark, germany, poland;
	    Fire fire;

    public:
	    CaveScene(Position position, Size size);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
