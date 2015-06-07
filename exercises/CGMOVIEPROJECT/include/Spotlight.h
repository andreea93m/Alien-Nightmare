//
// Created by sorin on 6/7/15.
//

#include "Object.h"
#include "Shader.h"

namespace AlienNightmare {
    class Spotlight : public Object {
    private:
	    GLfloat light_ambient[4];
	    GLfloat light_diffuse[4];
	    GLfloat light_specular[4];
	    GLfloat light_position[4];
	    GLfloat spot_pos[4];
	    GLfloat spot_dir[4];
	    GLfloat spot_cutoff, spot_quadratic_attenuation;

    public:
	    Spotlight(const Position &position, const Size &size);

	    virtual void render(float movieTime) override;

	    virtual void update() override;
    };
}
