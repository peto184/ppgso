//
// Created by peto184 on 26-Oct-17.
//

#pragma once
#ifndef PPGSO_PLAYER_H
#define PPGSO_PLAYER_H

#include <ppgso/ppgso.h>
#include "constants.h"
#include "scene.h"
#include "projectile.h"

class Player final {
public:
    Player();

    enum State {
        PLAYER_IN_AIR,
        PLAYER_ON_GROUND
    };

    const float PLAYER_SPEED = 5.0f;
    const float PLAYER_JUMP_STRENGTH = 10.0f;
    const float PLAYER_GRAVITY = 15.0f;

    const float RELOAD_TIME = 0.15;
    float mReload = 0.0;

    glm::vec3 mPosition{0.0,1.0,0};
    glm::vec3 mRotation{0,1.0,0};
    float mRotAngle = (float) (3 * M_PI / 2.0);
    glm::vec3 mScale{1.0,1.0,1.0};

    glm::mat4 mModelMatrix{1};

    glm::vec3 mDirection{0.0,0.0,0.0};
    enum State mPlayerState = PLAYER_ON_GROUND;
    enum Orientation mOrientation;

    bool update(Scene& scene, float dt);
    void render(Scene &scene);

private:
    static ppgso::Mesh *mMesh;
    static std::unique_ptr<ppgso::Mesh> mMeshJumping;
    static std::unique_ptr<ppgso::Mesh> mMeshStanding;

    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;

    bool checkCollisionY(Cube &c);
    bool checkCollisionX(Cube &c);
};


#endif //PPGSO_PLAYER_H
