//
// Created by sorin on 6/7/15.
//

#include "../include/Shader.h"

GLuint AlienNightmare::Shader::program;
const int AlienNightmare::Shader::MAX_LIGHTS = 8;
int AlienNightmare::Shader::lights[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

void AlienNightmare::Shader::init() {
	initPhongShader();

	glUseProgram(program);

	glUniform4f(glGetUniformLocation(program, "mycolor"), 1.0, 0.0, 0.0, 1.0);
	glUniform1i(glGetUniformLocation(program, "useTexturing"), false);
}

void AlienNightmare::Shader::initPhongShader() {
	//create program
	Shader::program = glCreateProgram();

	//compile shaders
	GLuint vertexshader = oogl::loadShader("shader/phong.vert", GL_VERTEX_SHADER);
	GLuint fragmentshader = oogl::loadShader("shader/phong.frag", GL_FRAGMENT_SHADER);

	//attach shaders
	glAttachShader(Shader::program, vertexshader);
	glAttachShader(Shader::program, fragmentshader);

	//link program
	GLint status;
	glLinkProgram(Shader::program);

	//check for link errors
	glGetProgramiv(Shader::program, GL_LINK_STATUS, &status);

	if (!status) {
		std::string error = "can't link program: " + oogl::GLSLProgram::getInfoLog(Shader::program);
		LOG_ERROR << error << std::endl;
		throw std::runtime_error(error);
	}
	else {
		LOG_DEBUG << "linked program - no errors" << std::endl;
	}
}

void AlienNightmare::Shader::enableTexture(GLuint texture) {
	glUniform1i(glGetUniformLocation(program, "useTexturing"), true);
	glUniform1i(glGetUniformLocation(program, "mytexture"), texture);
}

void AlienNightmare::Shader::disableTexture() {
	glUniform1i(glGetUniformLocation(program, "useTexturing"), false);
}

void AlienNightmare::Shader::enableLight(int light) {

	for (int i = 0; i < Shader::MAX_LIGHTS; ++i) {
		if (lights[i] == light) {
			return;
		}
	}

	for (int i = 0; i < Shader::MAX_LIGHTS; ++i) {
		if (lights[i] == -1) {
			lights[i] = light;

			glUniform1iv(glGetUniformLocation(program, "lightIndex"), 8, lights);

//			switch (i) {
//				case 0:
//					glUniform1i(glGetUniformLocation(program, "lightIndex0"), light);
//			        break;
//				case 1:
//					glUniform1i(glGetUniformLocation(program, "lightIndex1"), light);
//			        break;
//			}

			break;
		}
	}
}

void AlienNightmare::Shader::disableLight(int light) {
	for (int i = 0; i < Shader::MAX_LIGHTS; ++i) {
		if (lights[i] == light) {
			lights[i] = -1;

			glUniform1iv(glGetUniformLocation(program, "lightIndex"), 8, lights);

			break;
		}
	}
}
