//
// Created by peto184 on 09-Dec-17.
//

#ifndef PPGSO_OBJECT_H
#define PPGSO_OBJECT_H

#include <glm/vec3.hpp>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include "src/playground/constants.h"

class Scene;

class Object {
public:
    Object() = default;

    glm::vec3 mPosition;
    glm::vec3 mRotation;
    glm::vec3 mScale;
    glm::mat4 mModelMatrix;

    virtual bool update(Scene& scene, float dt) = 0;
    virtual void render(Scene &scene) = 0;

    bool checkCollisionY(Object& o1, Object& o2);
    bool checkCollisionX(Object& o1, Object& o2);

    const float SPEED = 5.0f;
    const float JUMP_STRENGHT = 10.0f;
    const float GRAVITY = 15.0f;

    float mRotAngle = 0.0f;
    glm::vec3 mDirection{0.0,0.0,0.0};
    enum Orientation mOrientation = Orientation ::LEFT;

};


#endif //PPGSO_OBJECT_H
