//
// Created by peto184 on 26-Oct-17.
//

#include "scene.h"

Scene::Scene() {
    for (unsigned long long int i = 0; i < mWorldHeight; i++){
        mGameWorld.emplace_back(std::vector<Cube>());
        for (int j = 0; j < mWorldLength; j++){
            Cube cube;
            mGameWorld.at(i).emplace_back(cube);
        }
    }
    //(*mPlayer).setPosition(2,2);
}

void Scene::render() {
    auto time = (float) glfwGetTime();

    (*mPlayer).render(*this);

    for (auto &i : mGameWorld) {
        for (auto &c : i) {
           c.render(*this);
        }
    }
}

void Scene::update(float dt) {
    auto time = (float) glfwGetTime();

    (*mCamera).update();
    (*mPlayer).update(*this, dt);

    for (unsigned long long int i = 0; i < mGameWorld.size(); i++) {
        for (unsigned long long int j = 0; j < mGameWorld.at(i).size(); j++) {
            Cube &c = mGameWorld.at(i).at(j);
            c.setPosition((int)j,(int) i);
            c.update(dt);
        }
    }

}
