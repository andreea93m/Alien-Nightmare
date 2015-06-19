//
// Created by sorin on 5/31/15.
//

#include "../include/GLhelpers.h"
#include "../include/Object.h"

AlienNightmare::Position::Position() : x(0), y(0), z(0) { }

AlienNightmare::Position::Position(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) { };

AlienNightmare::Position::Position(Object *object, GLfloat xp, GLfloat yp, GLfloat zp) : x(xp * object->size.width),
                                                                                         y(yp * object->size.height),
                                                                                         z(zp * object->size.depth) { }

AlienNightmare::Size::Size() : width(0), height(0), depth(0) { }

AlienNightmare::Size::Size(GLfloat width, GLfloat height, GLfloat depth) : width(width), height(height),
                                                                           depth(depth) { }
