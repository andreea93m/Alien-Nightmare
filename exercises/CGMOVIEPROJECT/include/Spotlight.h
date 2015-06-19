//
// Created by sorin on 6/7/15.
//

#include "Object.h"
#include "Shader.h"

namespace AlienNightmare {
    class Spotlight : public Object {
    private:
		std::vector<GLfloat> light_ambient;
		std::vector<GLfloat> light_diffuse;
		std::vector<GLfloat> light_specular;
		std::vector<GLfloat> light_position;
		std::vector<GLfloat> spot_pos;
		std::vector<GLfloat> spot_dir;
	    GLfloat fluctuation = -1, spot_cutoff, spot_linear_attenuation, spot_quadratic_attenuation;

    public:
	    Spotlight(const Position &position, const Size &size);

	    virtual void render() override;

	    virtual void update(float delta) override;
    };
}
