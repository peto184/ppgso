//
// Created by peto184 on 26-Oct-17.
//

#pragma once
#ifndef PPGSO_PLAYER_H
#define PPGSO_PLAYER_H

#include <ppgso/ppgso.h>

#include "object.h"

#include "src/playground/constants.h"
#include "src/playground/scene.h"
#include "projectile.h"

class Player final : public Object{
public:
    Player();

    enum State {
        PLAYER_IN_AIR,
        PLAYER_ON_GROUND
    };


    const float RELOAD_TIME = 0.0000001f;
    float mReload = 0.0;

    enum State mPlayerState = PLAYER_ON_GROUND;

    bool update(Scene& scene, float dt) override;
    void render(Scene &scene) override;

private:
    static ppgso::Mesh *mMesh;
    static std::unique_ptr<ppgso::Mesh> mMeshJumping;
    static std::unique_ptr<ppgso::Mesh> mMeshStanding;

    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;

};


#endif //PPGSO_PLAYER_H
