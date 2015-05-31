//
// Created by sorin on 5/30/15.
//

#pragma once

#include <vector>
#include "Scene.h"
#include "DemoObject.h"

namespace AlienNightmare {
    class RoomScene : public Scene {
    private:
	    DemoObject demoObject;

    public:
	    RoomScene(Position position, Size size);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
