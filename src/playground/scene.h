//
// Created by peto184 on 26-Oct-17.
//

#ifndef PPGSO_SCENE_H
#define PPGSO_SCENE_H

#include "cube.h"
class Cube;

#include "camera.h"
class Camera;

#include "player.h"
class Player;

#include "map.h"
class Map;

#include "background.h"
class Background;

#include "projectile.h"
class Projectile;

#include "finish.h"
class Finish;

#include "src/playground/entities/object.h"
class Object;

#include "src/playground/entities/enemy.h"
class Enemy;

#include <glm/glm.hpp>
#include <functional>


using namespace std;
using namespace glm;
using namespace ppgso;

class Scene {
public:

    std::vector<Cube> mCubes;
    std::vector<Projectile> mProjectiles;
    std::vector<Enemy> mEnemies;

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
