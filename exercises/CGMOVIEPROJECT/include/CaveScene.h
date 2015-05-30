//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"

namespace AlienNightmare {
    class CaveScene : public Scene {

    public:
	    CaveScene(Position position, Size size);

	    virtual void render(float movieTime);
	    virtual void update();
    };
}
