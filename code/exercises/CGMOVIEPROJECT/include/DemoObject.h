//
// Created by sorin on 5/31/15.
//

#pragma once

#include "include/Headers.h"

#include "Object.h"

namespace AlienNightmare {
    class DemoObject : public Object {

    public:
	    DemoObject(Position position, Size size);

	    void render();

	    void update(float delta);
    };
}
