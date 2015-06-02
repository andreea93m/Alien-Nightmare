//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"
#include "Sun.h"
#include "Polandball.h"

namespace AlienNightmare {
    class CaveScene : public Scene {
    private:
	    Sun sun;
	    Polandball denmark; // Added to test the lighting

    public:
	    CaveScene(Position position, Size size);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
