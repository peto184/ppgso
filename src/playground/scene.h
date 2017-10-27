//
// Created by peto184 on 26-Oct-17.
//

#ifndef PPGSO_SCENE_H
#define PPGSO_SCENE_H

class Cube;
#include "cube.h"
#include "camera.h"

class Player;
#include "player.h"
#include "map.h"

#include <glm/glm.hpp>

using namespace std;
using namespace glm;
using namespace ppgso;

class Scene {
public:
    ppgso::Shader program = {texture_vert_glsl, texture_frag_glsl};

    std::vector<Cube> mCubes;
    std::unique_ptr<Camera> mCamera;
    std::unique_ptr<Player> mPlayer;
    std::unique_ptr<Map> mMap;

    // Keyboard state
    std::map< int, int > keyboard;


    Scene();

    void render();
    void update(float dt);
    void loadAssets();

};


#endif //PPGSO_SCENE_H
