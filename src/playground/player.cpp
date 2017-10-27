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

bool Player::checkCollisionY(Cube& c){
    return mPosition.y + mScale.y >= c.mPosition.y && c.mPosition.y + c.mScale.y >= mPosition.y;
}

bool Player::checkCollisionX(Cube& c){
    return mPosition.x + mScale.x >= c.mPosition.x && c.mPosition.x + c.mScale.x >= mPosition.x;
}

bool Player::update(Scene &scene, float dt) {

    // === Set directions
    if(scene.keyboard[GLFW_KEY_LEFT]){
        mDirection.x = PLAYER_SPEED;
    }
    else if (scene.keyboard[GLFW_KEY_RIGHT]) {
        mDirection.x = -PLAYER_SPEED;
    }
    else {
        mDirection.x = 0;
    }
    if (scene.keyboard[GLFW_KEY_UP] && mPlayerState == PLAYER_STANDING){
        mDirection.y = PLAYER_JUMP_STRENGTH;
        mPlayerState = PLAYER_JUMPING;
    }

    // Gravity
    mDirection.y -= PLAYER_GRAVITY*dt;

    for (Cube c : scene.mCubes) {
        if (checkCollisionY(c) && checkCollisionX(c)) {
            // Nastala kolizia, pozri sa z ktorej strany je vacsie
            mPosition.y = c.mPosition.y + c.mScale.y/2.0f + mScale.y/2.0f;

            if (mDirection.y < 0.0)
                mDirection.y = 0.0f;

            mPlayerState = PLAYER_STANDING;
        }
    }

    // Move from position by direction in dt
    mPosition = mPosition + (mDirection*dt);
    mModelMatrix = glm::translate(mat4(1.0f), mPosition)
                        * glm::rotate(mat4(1.0f), (float) glfwGetTime(), mRotation)
                        * glm::scale(mat4(1.0f), mScale);

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
