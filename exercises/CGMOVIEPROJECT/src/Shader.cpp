//
// Created by sorin on 6/7/15.
//

#include "../include/Shader.h"

GLuint AlienNightmare::Shader::simpleshaderprogram;
GLuint AlienNightmare::Shader::phongshaderprogram;

AlienNightmare::Shader::shaders AlienNightmare::Shader::CURRENT_SHADER, AlienNightmare::Shader::PREVIOUS_SHADER;

void AlienNightmare::Shader::init() {
	initSimpleShader();
	initPhongShader();
}

void AlienNightmare::Shader::initSimpleShader() {
	//create program
	Shader::simpleshaderprogram = glCreateProgram();

	//compile shaders
	GLuint vertexshader = oogl::loadShader("shader/simpleshader.vert",GL_VERTEX_SHADER);
	GLuint fragmentshader = oogl::loadShader("shader/simpleshader.frag",GL_FRAGMENT_SHADER);

	//attach shaders
	glAttachShader(Shader::simpleshaderprogram, vertexshader);
	glAttachShader(Shader::simpleshaderprogram, fragmentshader);

	//link program
	GLint status;
	glLinkProgram(Shader::simpleshaderprogram);

	//check for link errors
	glGetProgramiv(Shader::simpleshaderprogram, GL_LINK_STATUS, &status);
	if (!status) {
		std::string error = "can't link program: " + oogl::GLSLProgram::getInfoLog(Shader::simpleshaderprogram);
		LOG_ERROR << error << std::endl;
		throw std::runtime_error(error);
	} else {
		LOG_DEBUG << "linked program - no errors" << std::endl;
	}
}

void AlienNightmare::Shader::initPhongShader() {
	//create program
	Shader::phongshaderprogram = glCreateProgram();

	//compile shaders
	GLuint vertexshader = oogl::loadShader("shader/phong.vert",GL_VERTEX_SHADER);
	GLuint fragmentshader = oogl::loadShader("shader/phong.frag",GL_FRAGMENT_SHADER);

	//attach shaders
	glAttachShader(Shader::phongshaderprogram, vertexshader);
	glAttachShader(Shader::phongshaderprogram, fragmentshader);

	//link program
	GLint status;
	glLinkProgram(Shader::phongshaderprogram);

	//check for link errors
	glGetProgramiv(Shader::phongshaderprogram, GL_LINK_STATUS, &status);

	if (!status) {
		std::string error = "can't link program: " + oogl::GLSLProgram::getInfoLog(Shader::phongshaderprogram);
		LOG_ERROR << error << std::endl;
		throw std::runtime_error(error);
	} else {
		LOG_DEBUG << "linked program - no errors" << std::endl;
	}
}

void AlienNightmare::Shader::useSimpleShader() {
	Shader::PREVIOUS_SHADER = Shader::CURRENT_SHADER;
	Shader::CURRENT_SHADER = Shader::shaders::SIMPLE;

	glUseProgram(simpleshaderprogram);

	/*
	Examples for setting uniform parameters in a shader program:

	Get Index of uniform parameter:
		glGetUniformLocation(program,"name")

	set uniform float:
		glUniform1f(glGetUniformLocation(program,"name") ,1.0);

	set uniform int (or texture unit):
		glUniform1i(glGetUniformLocation(program,"name") , 1);

	set uniform vec4 with 4 values:
		glUniform4f(glGetUniformLocation(program,"name") ,1.0,1.0,1.0,1.0);

	*/

	glUniform4f(glGetUniformLocation(simpleshaderprogram,"mycolor"),1.0,0.0,0.0,1.0);
	glUniform1i(glGetUniformLocation(simpleshaderprogram,"mytexture"),5);
	glUniform1f(glGetUniformLocation(simpleshaderprogram,"wobbletime"),0);
}

void AlienNightmare::Shader::usePhongShader() {
	Shader::PREVIOUS_SHADER = Shader::CURRENT_SHADER;
	Shader::CURRENT_SHADER = Shader::shaders::PHONG;

	glUseProgram(phongshaderprogram);

	glUniform4f(glGetUniformLocation(phongshaderprogram,"mycolor"),1.0,0.0,0.0,1.0);
	glUniform1i(glGetUniformLocation(phongshaderprogram,"mytexture"),5);
	glUniform1f(glGetUniformLocation(phongshaderprogram,"wobbletime"),0);
}

void AlienNightmare::Shader::useSmoothShader() {
	Shader::PREVIOUS_SHADER = Shader::CURRENT_SHADER;
	Shader::CURRENT_SHADER = Shader::shaders::SMOOTH;

	glUseProgram(0);

	glShadeModel(GL_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void AlienNightmare::Shader::undoShaderChange() {
	Shader::CURRENT_SHADER = Shader::PREVIOUS_SHADER;

	switch(Shader::CURRENT_SHADER) {
		case SMOOTH: { useSmoothShader(); break; };
		case SIMPLE: { useSimpleShader(); break; };
		case PHONG: { usePhongShader(); break; };
	}
}
