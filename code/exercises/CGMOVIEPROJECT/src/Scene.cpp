//
// Created by sorin on 5/30/15.
//
#include <oogl/Texture.h>
#include "../include/Scene.h"

AlienNightmare::Scene::Scene(Position position, Size size) : Object(position, size) {
	texture = oogl::loadTexture("textures/cave_textur.jpg");
	texture1 = oogl::loadTexture("textures/cave_texture.jpg");
}

void AlienNightmare::Scene::drawFloor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glPushMatrix();
	{
		glColor3f(red, green, blue);

		GLfloat color[] = {0.2, 0.2, 0.2, 1.0};
		glColor4fv(color);

		//Bottom
		glBegin(GL_QUADS);
		{
			glNormal3f(0, 1, 0);
			glVertex3f(size.width, 0, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, size.depth);
			glVertex3f(size.width, 0, size.depth);
		}
		glEnd();
	}
	glPopMatrix();
}

void AlienNightmare::Scene::drawWalls(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glPushMatrix();
	{

		// Up
		texture->bind(14);
		Shader::enableTexture(14);

		glBegin(GL_QUADS);
		{
			glNormal3f(0, -1, 0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(size.width, size.height, size.depth);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, size.height, size.depth);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, size.height, 0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(size.width, size.height, 0);
		}
		glEnd();
		Shader::disableTexture();
		texture->unbind();


		// Back
		texture->bind(11);
		Shader::enableTexture(11);

		glBegin(GL_QUADS);
		{
			glColor3f(red, green, blue);
			glNormal3f(1, 0, 1);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(size.width, size.height, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, size.height, 0);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, 0, 0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(size.width, 0, 0);

		}
		glEnd();

		Shader::disableTexture();
		texture->unbind();

		texture1->bind(12);
		Shader::enableTexture(12);

		//Left
		glBegin(GL_QUADS);
		{
			glColor3f(red, green, blue);
			glNormal3f(1, 0, 0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(0, size.height, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, size.height, size.depth);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, 0, size.depth);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(0, 0, 0);
		}
		glEnd();
		Shader::disableTexture();
		texture1->unbind();

		//Right
		texture1->bind(13);
		Shader::enableTexture(13);

		glBegin(GL_QUADS);
		{
			glColor3f(red, green, blue);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(size.width, size.height, size.depth);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(size.width, size.height, 0);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(size.width, 0, 0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(size.width, 0, size.depth);
		}
		glEnd();
		Shader::disableTexture();
		texture1->unbind();

	}
	glPopMatrix();
}
