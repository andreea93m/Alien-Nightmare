//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"
#include "DemoObject.h"

namespace AlienNightmare {
    class ChaseScene : public Scene {
    private:
	    DemoObject demoObject;

    public:
	    ChaseScene(Position position, Size size);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}