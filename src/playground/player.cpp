//
// Created by peto184 on 26-Oct-17.
//

#include "player.h"

std::unique_ptr<ppgso::Mesh> Player::mMesh;
std::unique_ptr<ppgso::Shader> Player::mShader;
std::unique_ptr<ppgso::Texture> Player::mTexture;

Player::Player(){
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("blocks/blockGold.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("sphere.obj");
}

void Player::setPosition(int x, int y){
    mPosition.x = (float) x;
    mPosition.y = (float) y;
}

bool Player::update(Scene &scene, float dt) {

    if(scene.keyboard[GLFW_KEY_LEFT]){
        mPosition.x += 10 * dt;
    }
    else if (scene.keyboard[GLFW_KEY_RIGHT]) {
        mPosition.x -= 10 * dt;
    }
    else if (scene.keyboard[GLFW_KEY_UP] && mPlayerState==PLAYER_STANDING){
        mJumpMomentum = 7.0;
        mPlayerState = PLAYER_JUMPING;
    }

    mPosition.y += mJumpMomentum * dt;
    mJumpMomentum -= 15.0 * dt;

    if (mPosition.y < 1.0) {
        mPosition.y = 1.0;
        mJumpMomentum = 0.0;
        mPlayerState = PLAYER_STANDING;
    }


    mModelMatrix = glm::scale(mat4(1.0f), mScale);
    mModelMatrix = glm::translate(mModelMatrix, mPosition);
    mModelMatrix = glm::rotate(mModelMatrix, (float)glfwGetTime(), {0.0,1.0,0.0});

    return true;
}

void Player::render(Scene &scene) {
    (*mShader).use();

    // use mCamera
    (*mShader).setUniform("ProjectionMatrix", (*scene.mCamera).projectionMatrix);
    (*mShader).setUniform("ViewMatrix", (*scene.mCamera).viewMatrix);

    // render mesh
    (*mShader).setUniform("ModelMatrix", mModelMatrix);
    (*mShader).setUniform("Texture", *mTexture);
    (*mMesh).render();
}
