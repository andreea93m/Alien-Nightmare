//
// Created by sorin on 6/7/15.
//

#pragma once

#include <oogl/gl_error.h>
#include <oogl/Model.h>
#include <oogl/Image.h>
#include <oogl/Texture.h>
#include <oogl/GLSLShader.h>
#include <oogl/GLSLProgram.h>
#include <sstream>

namespace AlienNightmare {
    class Shader {
    private:
	    static const int MAX_LIGHTS;
	    static GLuint program;

	    static void initPhongShader();

	    static int lights[8];

    public:
	    static void init();

	    static void enableTexture(GLuint texture);

	    static void disableTexture();

	    static void enableLight(int light);

	    static void disableLight(int light);
    };
}
