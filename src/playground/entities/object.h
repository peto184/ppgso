//
// Created by peto184 on 09-Dec-17.
//

#ifndef PPGSO_OBJECT_H
#define PPGSO_OBJECT_H

#include <glm/vec3.hpp>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>

class Scene;

class Object {
public:
    Object() = default;
    Object(const Object&) = default;
    Object(Object&&) = default;
    virtual ~Object() = default;

    glm::vec3 mPosition{0.0,0.0,0};
    glm::vec3 mRotation{0,1.0,0};
    glm::vec3 mScale{1.0,1.0,1.0};
    glm::mat4 mModelMatrix{1};

    virtual bool update(Scene& scene, float dt) = 0;
    virtual void render(Scene &scene) = 0;

    bool checkCollisionY(Object &o);
    bool checkCollisionX(Object &o);

};


#endif //PPGSO_OBJECT_H
