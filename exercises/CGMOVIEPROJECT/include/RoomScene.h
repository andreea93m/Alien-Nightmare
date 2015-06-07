//
// Created by sorin on 5/30/15.
//

#pragma once

#include <vector>
#include "Scene.h"
#include "Spotlight.h"
#include "Polandball.h"

namespace AlienNightmare {
    class RoomScene : public Scene {
    private:
	    Spotlight spotlight;
	    std::vector<Polandball *> polandballs;

    public:
	    RoomScene(Position position, Size size);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
