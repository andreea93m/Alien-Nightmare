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
	/**
	 * Encapsulates the Phong Shader and enables easy interactions with it
	 * (enableing / disabeing lights and textures)
	 */
    class Shader {
    private:
	    static const int MAX_LIGHTS;
	    static GLuint program;

	    static void initPhongShader();

	    static int lights[8];

    public:
	    static void init();

	    /**
	     * Enables rendering with a given texture
	     */
	    static void enableTexture(GLuint texture);

	    /**
	     * Disables textured rendering
	     */
	    static void disableTexture();

	    /**
	     * Enables a specific light
	     */
	    static void enableLight(int light);

	    /**
	     * Disables a specific light
	     */
	    static void disableLight(int light);
    };
}
