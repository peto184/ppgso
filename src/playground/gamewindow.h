//
// Created by peto184 on 24-Oct-17.
//

#ifndef PPGSO_GAMEWINDOW_H
#define PPGSO_GAMEWINDOW_H

#include <glm/glm.hpp>
#include <ppgso/ppgso.h>

#include "src/playground/entities/cube.h"
#include "scene.h"
#include "map.h"

#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <iostream>

using namespace std;
using namespace glm;
using namespace ppgso;

class GameWindow : public Window {
public:
    static const unsigned int GAME_WINDOW_WIDTH = 860;
    static const unsigned int GAME_WINDOW_HEIGHT = 640;

    vector<Scene> scenes;
    vector<Scene>::iterator currentScene;

    explicit GameWindow(const std::string &title = "Super Mario",
               unsigned int width = GAME_WINDOW_WIDTH,
               unsigned int height = GAME_WINDOW_HEIGHT);

    void onIdle() override;

    /*!
     * Handles pressed key when the window is focused
     * @param key Key code of the key being pressed/released
     * @param scanCode Scan code of the key being pressed/released
     * @param action Action indicating the key state change
     * @param mods Additional modifiers to consider
     */
    void onKey(int key, int scanCode, int action, int mods) override;

private:

protected:
};



#endif //PPGSO_GAMEWINDOW_H
