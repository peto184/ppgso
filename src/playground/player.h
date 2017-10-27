//
// Created by peto184 on 26-Oct-17.
//

#pragma once
#ifndef PPGSO_PLAYER_H
#define PPGSO_PLAYER_H

#include <ppgso/ppgso.h>
#include "scene.h"

class Player final {
public:
    Player();

    enum State {
        PLAYER_JUMPING,
        PLAYER_STANDING
    };

    const float PLAYER_SPEED = 5.0f;
    const float PLAYER_JUMP_STRENGTH = 10.0f;
    const float PLAYER_GRAVITY = 15.0f;

    glm::vec3 mPosition{0.0,1.0,0};
    glm::vec3 mRotation{0,1.0,0};
    glm::vec3 mScale{0.8,0.8,0.8};

    glm::mat4 mModelMatrix{1};

    glm::vec3 mDirection{0.0,0.0,0.0};
    enum State mPlayerState = PLAYER_STANDING;

    bool update(Scene& scene, float dt);
    void render(Scene &scene);

private:
    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;

    bool checkCollisionY(Cube &c);
    bool checkCollisionX(Cube &c);
};


#endif //PPGSO_PLAYER_H
