//
// Created by sorin on 6/7/15.
//

#include "../include/Spotlight.h"

AlienNightmare::Spotlight::Spotlight(const AlienNightmare::Position &position,
                                     const AlienNightmare::Size &size) : Object(position, size),
                                                                         light_ambient{0.0, 0.0, 0.0, 1.0},
                                                                         light_diffuse{1.0, 1.0, 1.0, 1.0},
                                                                         light_specular{0.0, 0.0, 0.0, 1.0},
                                                                         light_position{size.width / 2, size.height / 2,
                                                                                        size.depth / 2, 1.0},
                                                                         spot_pos{0.0, 0.0, 0.0, 1.0},
                                                                         spot_dir{0.0, -1.0f, 0.0},
                                                                         spot_cutoff(50.0),
                                                                         spot_quadratic_attenuation(0.01) { }

void AlienNightmare::Spotlight::render(float movieTime) {
	glPushMatrix();
	{
		moveToPosition();

		glLightfv(GL_LIGHT3, GL_POSITION, spot_pos);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, spot_cutoff);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_dir);
		glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, spot_quadratic_attenuation);

		glLightfv(GL_LIGHT3, GL_POSITION, light_position);
		glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);

		glEnable(GL_LIGHT3);

		Shader::enableLight(3);
	}
	glPopMatrix();
}

void AlienNightmare::Spotlight::update() {

}
