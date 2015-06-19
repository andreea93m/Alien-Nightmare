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
	/** The third and last scene
	 * Contains walls (one is tranparent), three polandballs, a spotlight
	 * and an alien outside the wall.
	 */
    class RoomScene : public Scene {
    private:
	    Spotlight spotlight;
	    std::vector<Polandball *> polandballs;
	    Alien alien;

    public:
	    RoomScene(Position position, Size size);

	    virtual void render();

	    virtual void update(float delta);
    };
}
