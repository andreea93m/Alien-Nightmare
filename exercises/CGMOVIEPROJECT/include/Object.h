//
// Created by sorin on 5/31/15.
//

#pragma once

// Forward declaration
namespace AlienNightmare {
    class Object;
}

#include "GLhelpers.h"

namespace AlienNightmare {
	/**
	 * All the objects that will be drawn on screen inherit from this class
	 * Provides basic fields like position, size and render and update methods.
	 */
    class Object {
    protected:
	    void moveToPosition();

    public:
	    Size size;
	    Position position;

	    /**
	     * Helper method for debugging
	     * Draws the relative coordinate system of the object
	     */
	    static void drawCoordinateSystem();

	    Object(Position position, Size size);

	    /**
	     * To be called each time a frame is rendered
	     */
	    virtual void render() = 0;

	    /**
	     * To be called each time the objects needs to be updated
	     * delta - The elapsed time since the last frame (all animations
	     * should use it as a "scaling" factor)
	     */
	    virtual void update(float delta) = 0;

	    /**
	     * Places the object inside another object at the specified proportions
	     * Usefull for stuff like: Place X in the center of Y
	     * (Y->place(X, 0.5, 0.5, 0.5)
	     */
	    void placeRelative(Object *object, GLfloat xp, GLfloat yp, GLfloat zp);
    };
}
