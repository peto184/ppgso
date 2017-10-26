//
// Created by peto184 on 26-Oct-17.
//

#ifndef PPGSO_SCENE_H
#define PPGSO_SCENE_H

class Cube;
#include "cube.h"
#include "camera.h"

#include <glm/glm.hpp>

using namespace std;
using namespace glm;
using namespace ppgso;

class Scene {
public:
    ppgso::Shader program = {texture_vert_glsl, texture_frag_glsl};

    static const int mWorldLength = 8;
    static const int mWorldHeight = 5;

    std::vector<std::vector<Cube> > mGameWorld;
    std::unique_ptr<Camera> camera;

    Scene();

    void render();
    void update();

};


#endif //PPGSO_SCENE_H
