//
// Created by sorin on 6/8/15.
//

#include <oogl/Model.h>
#include "../include/Alien.h"

AlienNightmare::Alien::Alien(const AlienNightmare::Position &position, const AlienNightmare::Size &size) : Object(position, size) {
	model = (oogl::model::ModelObj *) oogl::loadModel("models/Alien_Queen/Alien_Queen.obj");
}

void AlienNightmare::Alien::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

		glTranslatef(0, 1, 0);
		glScalef(2, 2, 2);
		model->model->materials[1].ambient[3] = 0;
		glBindTexture(GL_TEXTURE_2D, model->model->textures[1].id);
		Shader::enableTexture(model->model->textures[1].id);
		model->render();
		Shader::disableTexture();
	}
	glPopMatrix();
}

void AlienNightmare::Alien::update() {

}
