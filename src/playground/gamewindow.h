//
// Created by peto184 on 24-Oct-17.
//

#ifndef PPGSO_GAMEWINDOW_H
#define PPGSO_GAMEWINDOW_H

#include <glm/glm.hpp>
#include <ppgso/ppgso.h>
#include <cmake-build-debug/shaders/texture_vert_glsl.h>
#include <cmake-build-debug/shaders/texture_frag_glsl.h>
#include "cube.h"

#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <iostream>

using namespace ppgso;
using namespace std;

class GameWindow : public Window {
public:
    static const unsigned int GAME_WINDOW_WIDTH = 1280;
    static const unsigned int GAME_WINDOW_HEIGHT = 1024;

    vector<Cube> cube_vector;

    Shader program = {texture_vert_glsl, texture_frag_glsl};

    explicit GameWindow(const std::string &title = "Super Mario",
               unsigned int width = GAME_WINDOW_WIDTH,
               unsigned int height = GAME_WINDOW_HEIGHT);

    void onIdle() override;

private:

protected:

};



#endif //PPGSO_GAMEWINDOW_H
