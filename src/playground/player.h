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

    glm::vec3 mPosition{0.0,1.0,0};
    glm::vec3 mRotation{0,0,0};
    glm::vec3 mScale{1,1,1};
    glm::mat4 mModelMatrix{1};

    float mJumpMomentum = 0.0f;
    enum State mPlayerState = PLAYER_STANDING;

    bool update(Scene& scene, float dt);
    void render(Scene &scene);

    void setPosition(int x, int y);

private:
    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;
};


#endif //PPGSO_PLAYER_H
