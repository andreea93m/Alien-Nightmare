//
// Created by sorin on 5/30/15.
//

#include "../include/RoomScene.h"

AlienNightmare::RoomScene::RoomScene(Position position, Size size)
		: Scene(position, size), spotlight(Position(this, 0.4, 0.5, 0.8), Size(1, 1, 1)), alien(Position(this, 0.5, 0.0, 0.0), Size(1, 1, 1)) {

	Polandball *poland = new Polandball(1, 0, "textures/poland.png");
	poland->placeRelative(this, 0.3, 0, 0.3);
	poland->setJump(0.15, 5);

	Polandball *germany = new Polandball(1, 0, "textures/germany.png");
	germany->placeRelative(this, 0.6, 0, 0.9);
	germany->setJump(0.13, 6);

	Polandball *denmark = new Polandball(1, 0, "textures/denmark.png");
	denmark->placeRelative(this, 0.7, 0, 0.6);
	denmark->setJump(0.1, 4);

	polandballs.push_back(poland);
	polandballs.push_back(germany);
	polandballs.push_back(denmark);
}

void AlienNightmare::RoomScene::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();
		Size room = Size(8, spotlight.position.y + spotlight.size.height + 0.01f, 6);
		//drawWalls(0, 0, 1, 1);

		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);

		alien.render(movieTime);

		spotlight.render(movieTime);
		drawFloor(0, 0, 1, 1);

		glColor3f(1, 1, 1);

		glDisable(GL_BLEND);
		for (int i = 0; i < polandballs.size(); ++i) {
			polandballs[i]->render(movieTime);
		}
		glEnable(GL_BLEND);

		glPushMatrix();
		{
			glTranslatef(1,0, 2);
			// glColor3f(red, green, blue);

			// Top
			glBegin(GL_QUADS);
			{
				GLfloat color[] = {0.2, 0.2, 0.2, 1.0};
				glColor4fv(color);
				glNormal3f(1, -1, 0);
				glVertex3f(room.width, room.height, room.depth);
				glVertex3f(0, room.height, room.depth);
				glVertex3f(0, room.height, 0);
				glVertex3f(room.width, room.height, 0);
			};
			glEnd();

			// Back
			glBegin(GL_QUADS);
			{
				GLfloat color[] = {0.2, 0.2, 0.2, 0.5};
				glColor4fv(color);
				// glMaterialfv(GL_FRONT, GL_EMISS, color);
				glNormal3f(0, 0, 1);
				glVertex3f(room.width, room.height, 0);
				glVertex3f(0, room.height, 0);
				glVertex3f(0, 0, 0);
				glVertex3f(room.width, 0, 0);
			}
			glEnd();

//			glDisable(GL_BLEND);
//			//Left
			glDisable(GL_BLEND);
			glBegin(GL_QUADS);
			{
				GLfloat color[] = {0.2, 0.2, 0.2, 1.0};
				glColor4fv(color);
				glNormal3f(1, 0, 0);
				glVertex3f(0, room.height, 0);
				glVertex3f(0, room.height, room.depth);
				glVertex3f(0, 0, room.depth);
				glVertex3f(0, 0, 0);
			}
			glEnd();
//
			//Right
			glBegin(GL_QUADS);
			{
				GLfloat color[] = {0.2, 0.2, 0.2, 1.0};
				glColor4fv(color);
				glNormal3f(-1, 0, 0);
				glVertex3f(room.width, room.height, room.depth);
				glVertex3f(room.width, room.height, 0);
				glVertex3f(room.width, 0, 0);
				glVertex3f(room.width, 0, room.depth);
			}
			glEnd();
		}
		glPopMatrix();

		glDisable(GL_BLEND);
	}
	glPopMatrix();
}

void AlienNightmare::RoomScene::update() {
	for (int i = 0; i < polandballs.size(); ++i) {
		polandballs[i]->update();
	}
}
