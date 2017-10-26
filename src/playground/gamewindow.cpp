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

    // init scene
    auto camera = std::make_unique<Camera>(60.0f, 1.0f, 0.1f, 100.0f);
    (*camera).position.z = -10.0f;
    (*camera).position.y = 3.0f;
    (*camera).position.x = -3.0f;
    mScene.mCamera = move(camera);

    auto player = std::make_unique<Player>();
    mScene.mPlayer = move(player);
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
}
