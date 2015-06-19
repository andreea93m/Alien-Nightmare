//
// Created by sorin on 6/7/15.
//

#include "../include/Spotlight.h"

AlienNightmare::Spotlight::Spotlight(const AlienNightmare::Position &position,
                                     const AlienNightmare::Size &size) : Object(position, size),
                                                                         light_ambient({0.0, 0.0, 0.0, 1.0}),
                                                                         light_diffuse({1.0, 1.0, 1.0, 1.0}),
                                                                         light_specular({0.0, 0.0, 0.0, 1.0}),
                                                                         light_position({size.width, size.height,
                                                                                        size.depth, 1.0}),
                                                                         spot_pos({0.0, 0.0, 0.0, 1.0}),
                                                                         spot_dir({0.0, -0.5f, -0.5f}),
                                                                         spot_cutoff(20.0),
                                                                         spot_linear_attenuation(0.0),
                                                                         spot_quadratic_attenuation(0.0) { }

void AlienNightmare::Spotlight::render() {
	glPushMatrix();
	{
		moveToPosition();


		glLightfv(GL_LIGHT3, GL_POSITION, &spot_pos[0]);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, spot_cutoff);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, &spot_dir[0]);
		glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 0.3);
		glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, spot_linear_attenuation);
		glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, spot_quadratic_attenuation);

		glLightfv(GL_LIGHT3, GL_POSITION, &light_position[0]);
		glLightfv(GL_LIGHT3, GL_AMBIENT, &light_ambient[0]);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, &light_diffuse[0]);
		glLightfv(GL_LIGHT3, GL_SPECULAR, &light_specular[0]);

		glEnable(GL_LIGHT3);

		Shader::enableLight(3);
	}
	glPopMatrix();
}

void AlienNightmare::Spotlight::update(float delta) {
	fluctuation += delta * 0.01;
	light_diffuse[0] = light_specular[0] = sinf(fluctuation);
	light_diffuse[1] = light_specular[1] = cosf(fluctuation);


}
