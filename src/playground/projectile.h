//
// Created by peto184 on 05-Nov-17.
//

#ifndef PPGSO_PROJECTILE_H
#define PPGSO_PROJECTILE_H


#include <glm/vec3.hpp>
#include "scene.h"
#include "player.h"

class Projectile {
public:
    float PROJECTILE_SPEED = 20.0f;
    float MAX_AGE = 1.0f;

    float age = 0.0f;

    Projectile(glm::vec3 playerPosition, Orientation orientation);
    Projectile();

    Orientation mOrientation;

    glm::vec3 mPosition{0.0,0.0,0.0};
    glm::vec3 mRotation{0,1.0,0};
    glm::vec3 mScale{.2,.2,.2};

    glm::mat4 mModelMatrix{1};

    bool update(Scene& scene, float dt);
    void render(Scene &scene);

    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;
};


#endif //PPGSO_PROJECTILE_H
