//
// Created by peto184 on 24-Oct-17.
//

#include "gamewindow.h"

using namespace glm;
using namespace std;

GameWindow::GameWindow(const std::string &title, unsigned int width, unsigned int height)
        : Window(title, width, height) {

    // Enable Z-Buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Enable polygon culling
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    scenes.emplace_back(Scene("levels/map1"));
    scenes.emplace_back(Scene("levels/map2"));
    scenes.emplace_back(Scene("levels/map3"));

    currentScene = scenes.begin();
}

void GameWindow::onIdle() {
    // Set gray background
    // Light blue RGB = 135,206,250
    glClearColor((float) (135.0/255.0),(float) (206.0/255.0), (float) (250.0/255.0), 0.0f);
    // Clear depth and color buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // Track time
    static auto time = (float) glfwGetTime();
    float dt = (float) glfwGetTime() - time;
    time = (float) glfwGetTime();

    currentScene->update(dt);
    currentScene->render();

    // IF R was pressed
    if (currentScene->resetLevel){
        currentScene->initScene(currentScene->mMap->filepath);
        currentScene->resetLevel = false;
    }

    bool reset = false;
    if (currentScene->nextLevel){
        if(currentScene == scenes.end()){
            reset = true;
        }
        else {
            currentScene++;
        }
    }

    if (reset){
        for(Scene &s : scenes){
            s.initScene(s.mMap->filepath);
        }
        currentScene = scenes.begin();
    }

}

void GameWindow::onKey(int key, int scanCode, int action, int mods) {
    currentScene->keyboard[key] = action;

    if (key == GLFW_KEY_R && action == GLFW_PRESS){
        currentScene->resetLevel = true;
    }
    if (key == GLFW_KEY_C && action == GLFW_PRESS) {
        currentScene->mCamera->mSwitchCamera = true;
    }

}
