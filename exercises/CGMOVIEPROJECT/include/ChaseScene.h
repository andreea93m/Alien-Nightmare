//
// Created by sorin on 5/30/15.
//

#pragma once

#include "Scene.h"
#include "Sun.h"
#include "Polandball.h"
#include "DemoObject.h"
#include "Warrior.h"
#include "Parallelepiped.h"
#include "Animal.h"

namespace AlienNightmare {
    class ChaseScene : public Scene {
    private:
    	Sun sun;
    	Polandball germany;
    	Animal animal;
    	Warrior warrior;
	    DemoObject demoObject;

    public:
	    ChaseScene(Position position, Size size);

	    virtual void render();

	    virtual void update();
    };
}
