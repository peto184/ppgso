//
// Created by peto184 on 05-Nov-17.
//

#ifndef PPGSO_PROJECTILE_H
#define PPGSO_PROJECTILE_H

#include <glm/vec3.hpp>
#include "src/playground/scene.h"
#include "src/playground/entities/player.h"

class Projectile : public Object {
public:
    Projectile(glm::vec3 playerPosition, Orientation orientation);
    Projectile();
    ~Projectile();

    Orientation mOrientation = Orientation::LEFT;

    glm::vec3 mColor{0.0,0.0,0.0};
    float PROJECTILE_SPEED = 30.0f;
    float MAX_AGE = 5.0f;
    float PROJECTILE_WEIGHT = 0.05f;

    float age = 0.0f;
    float y_speed = 0.0f;

    bool update(Scene& scene, float dt) override;
    void render(Scene &scene) override;

    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;

};


#endif //PPGSO_PROJECTILE_H
