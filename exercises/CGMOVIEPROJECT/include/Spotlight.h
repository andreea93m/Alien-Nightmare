//
// Created by sorin on 6/7/15.
//

#include "Object.h"

namespace AlienNightmare {
    class Spotlight : public Object {

    public:
	    Spotlight(const Position &position, const Size &size);

	    virtual void render(float movieTime) override;

	    virtual void update() override;
    };
}
