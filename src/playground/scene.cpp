//
// Created by peto184 on 26-Oct-17.
//

#include "scene.h"

Scene::Scene() {
    for (unsigned long long int i = 0; i < mWorldHeight; i++){
        mGameWorld.emplace_back(std::vector<Cube>());
        for (int j = 0; j < mWorldLength; j++){
            Cube c;
            mGameWorld.at(i).emplace_back(c);
        }
    }
}

void Scene::render() {
    auto time = (float) glfwGetTime();

    for (auto &i : mGameWorld) {
        for (auto &c : i) {
           c.render(*this);
        }
    }
}

void Scene::update() {
    auto time = (float) glfwGetTime();

    for (unsigned long long int i = 0; i < mGameWorld.size(); i++) {
        for (unsigned long long int j = 0; j < mGameWorld.at(i).size(); j++) {
            Cube &c = mGameWorld.at(i).at(j);
            c.mModelMatrix = rotate(mat4{}, time, {0.0f, 0.5f* pow(-1.0, i) , 0.0f});
            c.mModelMatrix = translate(mat4{}, {float(i), float(j), 0.0});
        }
    }

}
