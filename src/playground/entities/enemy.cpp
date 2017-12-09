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
}

bool Enemy::update(Scene &scene, float time) {
    mModelMatrix = glm::translate(glm::mat4(1.0f), mPosition)
                   * glm::rotate(glm::mat4(1.0f), 0.0f, mRotation)
                   * glm::scale(glm::mat4(1.0f), mScale);

    return false;
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
