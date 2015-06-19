//
// Created by sorin on 5/30/15.
//

#pragma once

#include <vector>
#include "Scene.h"
#include "Spotlight.h"
#include "Polandball.h"
#include "Alien.h"

namespace AlienNightmare {
    class RoomScene : public Scene {
    private:
	    Spotlight spotlight;
	    std::vector<Polandball *> polandballs;
	    Alien alien;

    public:
	    RoomScene(Position position, Size size);

	    virtual void render();

	    virtual void update();
    };
}
