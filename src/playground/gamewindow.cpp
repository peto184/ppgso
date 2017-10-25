//
// Created by peto184 on 24-Oct-17.
//

#include "gamewindow.h"
#include "cube.h"

using namespace glm;
using namespace std;

GameWindow::GameWindow(const std::string &title, unsigned int width, unsigned int height)
        : Window(title, width, height) {

    hideCursor();

    // Enable Z-Buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Enable polygon culling
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
}

void GameWindow::onIdle() {
    // Set gray background
    glClearColor(.5f,.5f,.5f,0.0f);
    // Clear depth and color buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto time = (float) glfwGetTime();
    // create object matrices
    cube.modelMatrix = rotate(mat4{}, time, {0.5f, 1.0f, 0.0f});

    // Camera position/rotation - for example, translate camera a bit backwards (positive value in Z axis), so we can see the objects
    auto cameraMat = translate(mat4{}, {0.0f, 0.0f, -2.5f});
    program.setUniform("ViewMatrix", cameraMat);

    // Update camera position with perspective projection
    program.setUniform("ProjectionMatrix", perspective((PI / 180.f) * 60.0f, 1.0f, 0.1f, 10.0f));

    program.setUniform("Texture", cube.getTexture());
    program.setUniform("ModelMatrix", cube.modelMatrix);
    cube.getMesh().render();

}
