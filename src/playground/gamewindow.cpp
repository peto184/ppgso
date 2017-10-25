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

    // insert the cubes
    for (int i = 0; i < 5; i++){
        cube_vector.emplace_back(Cube(ppgso::Texture(image::loadBMP("sphere.bmp")), ppgso::Mesh("cube.obj")));
    }

}

void GameWindow::onIdle() {
    // Set gray background
    glClearColor(.5f,.5f,.5f,0.0f);
    // Clear depth and color buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto time = (float) glfwGetTime();

    for (int i = 0; i < cube_vector.size(); i++){
        Cube c = cube_vector.at(i);
        c.modelMatrix = rotate(mat4{}, time, {0.0f, 0.5f * pow(-1.0, i), 0.0f});
        c.modelMatrix = translate(c.modelMatrix, {0.0, 0.0, float(i)});
        program.setUniform("Texture", c.getTexture());
        program.setUniform("ModelMatrix", c.modelMatrix);
        c.getMesh().render();
    }

    // create object matrices

    // Camera position/rotation - for example, translate camera a bit backwards (positive value in Z axis), so we can see the objects
    auto cameraMat = translate(mat4{}, {0.0f, 0.0f, -5.0f});
    program.setUniform("ViewMatrix", cameraMat);

    // Update camera position with perspective projection
    program.setUniform("ProjectionMatrix", perspective((PI / 180.f) * 60.0f, 1.0f, 0.1f, 10.0f));

}
