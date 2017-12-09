//
// Created by peto184 on 26-Oct-17.
//

#include "scene.h"

Scene::Scene(string mapPath){
    initScene(mapPath);
};

void Scene::initScene(string mapPath){
    // Clear objects
    mCubes.clear();
    mEnemies.clear();
    mProjectiles.clear();

    // loadMap
    mMap = std::make_unique<Map>(mapPath);

    // init scene
    mCamera = std::make_unique<Camera>(60.0f, 1.0f, 0.1f, 100.0f);

    mPlayer = std::make_unique<Player>();
    mBackground = std::make_unique<Background>();
    mFinish = std::make_unique<Finish>();

    resetLevel = false;
    nextLevel = false;

    loadAssets();
}

void Scene::loadAssets(){
    Map& m = *mMap;

    for (auto i = 0; i < m.map.size(); i++){
        for (auto j = 0; j < m.map.at(i).size(); j++) {
            switch(m.map[i][j]) {
                case Map::Tile::BLOCK: {
                    Cube cube;

                    cube.mPosition.x = (float) (j);
                    cube.mPosition.y = (float) (m.map.size() - i);
                    mCubes.push_back(cube);
                    break;
                }
                case Map::Tile::PLAYER: {
                    (*mPlayer).mPosition.x = (j);
                    (*mPlayer).mPosition.y = (m.map.size() - i);
                    break;
                }
                case Map::Tile::FINISH: {
                    (*mFinish).mPosition.x = j;
                    (*mFinish).mPosition.y = (m.map.size() - i);
                    break;
                }
                case Map::Tile::ENEMY: {
                    auto e = make_unique<Enemy>();

                    e->mPosition.x = (float) (j);
                    e->mPosition.y = (float) (m.map.size() - i);
                    mEnemies.push_back(move(e));
                    break;
                }
                case Map::Tile::AIR:
                    break;
                default:
                    cout << "invalid choice" << endl;
            }
        }
    }
}

void Scene::render() {
    (*mBackground).render(*this);

    if (mCamera->mCameraMode != Camera::FIRST_PERSON) {
        (*mPlayer).render(*this);
    }

    for (auto &c : mCubes) {
        c.render(*this);
    }

    for (auto &e : mEnemies){
        e->render(*this);
    }

    (*mFinish).render(*this);

    for (auto &p : mProjectiles) {
        p->render(*this);
    }
}

void Scene::update(float dt) {
    // Update camera
    (*mCamera).update(*this);

    // Update background and player
    (*mBackground).update(*this, dt);
    (*mPlayer).update(*this, dt);

    // Update cubes
    for (auto &c : mCubes) {
        c.update(*this, dt);
    }

    for (auto &e : mEnemies){
        e->update(*this, dt);
    }

    (*mFinish).update(*this, dt);

    //cout << "Projectiles: " << mProjectiles.size() << " Cubes: " << mCubes.size() << endl;

    // Update enemies
    for (auto it = mEnemies.begin(); it != mEnemies.end(); ){
        auto obj = it->get();

        if (!obj->update(*this, dt)) {
            it = mEnemies.erase(it);
        } else {
            ++it;
        }
    }


    // Update projectiles
    for (auto it = mProjectiles.begin(); it != mProjectiles.end(); ){
        auto obj = it->get();

        if (!obj->update(*this, dt)) {
            it = mProjectiles.erase(it);
        } else {
            ++it;
        }
    }


}
