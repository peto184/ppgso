//
// Created by peto184 on 08-Dec-17.
//

#include <cmake-build-debug/shaders/diffuse_vert_glsl.h>
#include <cmake-build-debug/shaders/diffuse_frag_glsl.h>

#include "enemy.h"
#include "src/playground/scene.h"

std::unique_ptr<ppgso::Mesh> Enemy::mMesh;
std::unique_ptr<ppgso::Shader> Enemy::mShader;
std::unique_ptr<ppgso::Texture> Enemy::mTexture;

Enemy::Enemy() {
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("blocks/redstone.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("Santa Claus/Santa Claus.obj");

    mRotAngle = (float) (3 * M_PI / 2.0);
    mHealth = MAX_HEALTH;
    mOrientation = Orientation ::LEFT;

    mPosition = {0.0, 0.0, 0.0};
    mScale = {1.5, 2.5, 1.5};
    mDirection = {0.0, 0.0, 0.0};
    mRotation = {0.0, 1.0, 0.0};
}

bool Enemy::update(Scene &scene, float dt) {
    if (mHealth <= 0){
        return false;
    }

    mDirection.y -= GRAVITY*dt;

    for (Cube &c : scene.mCubes) {
        // Check collision only if player is falling
        vec3 dist(glm::distance(mPosition, c.mPosition));

        if (dist.y < c.mScale.y && dist.x < c.mScale.x && mDirection.y < 0) {
            mPosition.y = c.mPosition.y + c.mScale.y/2.0f;

            if (mDirection.y < 0.0)
                mDirection.y = 0.0f;

            break;
        }
    }

    mPosition = mPosition + (mDirection*dt);
    mModelMatrix = glm::translate(glm::mat4(1.0f), mPosition)
                   * glm::rotate(mat4(1.0f), mRotAngle, mRotation)
                   * glm::scale(glm::mat4(1.0f), mScale);

    return true;
}

void Enemy::render(Scene &scene) {
    (*mShader).use();

    // Set up light
    (*mShader).setUniform("LightDirection", {0.0, 1.0, 0.0});

    // use mCamera
    (*mShader).setUniform("ProjectionMatrix", (*scene.mCamera).projectionMatrix);
    (*mShader).setUniform("ViewMatrix", (*scene.mCamera).viewMatrix);

    // render mesh
    (*mShader).setUniform("ModelMatrix", mModelMatrix);
    (*mShader).setUniform("Texture", *mTexture);
    (*mMesh).render();
}
