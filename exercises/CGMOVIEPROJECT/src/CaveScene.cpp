//
// Created by sorin on 5/30/15.
//

#include "../include/CaveScene.h"

void AlienNightmare::CaveScene::render(float movieTime) {
    glPushMatrix();
    {
        glTranslatef(- spacing(), 0, 0);
        Scene::render(movieTime);
    }
    glPopMatrix();
}
