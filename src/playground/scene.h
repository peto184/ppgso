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

class Background;
#include "background.h"

class Projectile;
#include "projectile.h"

#include <glm/glm.hpp>
#include <algorithm>
#include <functional>

class Finish;
#include "finish.h"

using namespace std;
using namespace glm;
using namespace ppgso;

class Camera;

class Scene {
public:

    std::vector<Cube> mCubes;
    std::vector<Projectile> mProjectiles;

    std::unique_ptr<Camera> mCamera;
    std::unique_ptr<Background> mBackground;
    std::unique_ptr<Player> mPlayer;
    std::unique_ptr<Map> mMap;
    std::unique_ptr<Finish> mFinish;

    // Keyboard state
    std::map< int, int > keyboard;

    Scene(string mapPath);

    bool nextLevel = false;
    bool resetLevel = false;

    void render();
    void update(float dt);
    void loadAssets();
    void initScene(string mapPath);

};


#endif //PPGSO_SCENE_H
