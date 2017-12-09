//
// Created by peto184 on 09-Dec-17.
//

#ifndef PPGSO_MOVABLE_H
#define PPGSO_MOVABLE_H

#include <glm/vec3.hpp>
#include "src/playground/constants.h"

class Movable {
    const float SPEED = 5.0f;
    const float JUMP_STRENGHT = 10.0f;
    const float GRAVITY = 15.0f;

    glm::vec3 mDirection{0.0,0.0,0.0};
    enum Orientation mOrientation;

};


#endif //PPGSO_MOVABLE_H
