//
// Created by peto184 on 26-Oct-17.
//

#include "scene.h"

Scene::Scene() = default;

void Scene::loadAssets(){
    Map& m = *mMap;

    for (auto i = 0; i < m.map.size(); i++){
        for (auto j = 0; j < m.map.at(i).size(); j++) {
            switch(m.map[i][j]) {
                case Map::Tile::BLOCK: {
                    Cube cube;

                    cube.mPosition.x = (float) (j);
                    cube.mPosition.y = (float) (m.map.size() - i);
                    mCubes.emplace_back(cube);
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

    (*mFinish).render(*this);

    for (auto &p : mProjectiles) {
        p.render(*this);
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
        c.update(dt);
    }

    (*mFinish).update(dt);

    // Update projectiles
    for (auto it = mProjectiles.begin(); it != mProjectiles.end(); ){
        if (!it->update(*this, dt)) {
            it = mProjectiles.erase(it);
        } else {
            ++it;
        }
    }

}
