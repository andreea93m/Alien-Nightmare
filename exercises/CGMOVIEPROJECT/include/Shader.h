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
	    enum shaders { SMOOTH, SIMPLE, PHONG };
	    static shaders CURRENT_SHADER, PREVIOUS_SHADER;

        static GLuint simpleshaderprogram;
		static GLuint phongshaderprogram;

		static void initSimpleShader();
		static void initPhongShader();

    public:
	    static void init();

	    static void useSmoothShader();
	    static void useSimpleShader();
	    static void usePhongShader();

	    static void undoShaderChange();
    };
}
