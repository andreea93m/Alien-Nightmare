//
// Created by sorin on 5/31/15.
//

#include "../include/Object.h"

AlienNightmare::Object::Object(Position position, Size size) : position(position), size(size) { }

void AlienNightmare::Object::moveToPosition() {
	glTranslatef(position.x, position.y, position.z);
}
