//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"
#include "Sun.h"
#include "Polandball.h"
#include "DemoObject.h"
#include "Warrior.h"

namespace AlienNightmare {
    class ChaseScene : public Scene {
    private:
    	Sun sun;
    	Polandball germany;
    	Warrior warrior;
	    DemoObject demoObject;

    public:
	    ChaseScene(Position position, Size size);

	    virtual void render(float movieTime);

	    virtual void update();
    };
}
