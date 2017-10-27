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

    initScene();
}

void GameWindow::initScene(){
    // Clear objects
    mScene.mCubes.clear();

    // loadMap
    auto map = std::make_unique<Map>("map1");
    mScene.mMap = move(map);

    // init scene
    auto camera = std::make_unique<Camera>(60.0f, 1.0f, 0.1f, 100.0f);
    mScene.mCamera = move(camera);

    auto player = std::make_unique<Player>();
    mScene.mPlayer = move(player);

    mScene.loadAssets();
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

    mScene.update(dt);
    mScene.render();
}

void GameWindow::onKey(int key, int scanCode, int action, int mods) {
    mScene.keyboard[key] = action;

    if (key == GLFW_KEY_R && action == GLFW_PRESS){
        initScene();
    }

}
