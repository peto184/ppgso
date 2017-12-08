//
// Created by peter on 27-Nov-17.
//


#include "finish.h"

std::unique_ptr<ppgso::Mesh> Finish::mMesh;
std::unique_ptr<ppgso::Shader> Finish::mShader;
std::unique_ptr<ppgso::Texture> Finish::mTexture;

Finish::Finish() {
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("blocks/lapis.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("sphere.obj");
}

bool Finish::update(Scene &scene, float time) {

    if (checkCollisionX(*(scene).mPlayer) && checkCollisionY(*(scene).mPlayer)){
        scene.nextLevel = true;
    }

    mModelMatrix = glm::translate(mat4(1.0f), mPosition)
                   * glm::rotate(mat4(1.0f), (float) glfwGetTime(), mRotation)
                   * glm::scale(mat4(1.0f), mScale);

    return false;
}

void Finish::render(Scene &scene) {
    (*mShader).use();

    vec3 playerPos = scene.mPlayer->mPosition;
    vec3 lightDir = {sin(glfwGetTime()) * 3.0, cos(glfwGetTime() * 2.1) * 3.0, 1};

    // Set up light
    (*mShader).setUniform("LightDirection", playerPos);

    // use mCamera
    (*mShader).setUniform("ProjectionMatrix", (*scene.mCamera).projectionMatrix);
    (*mShader).setUniform("ViewMatrix", (*scene.mCamera).viewMatrix);

    // render mesh
    (*mShader).setUniform("ModelMatrix", mModelMatrix);
    (*mShader).setUniform("Texture", *mTexture);
    (*mMesh).render();
}

bool Finish::checkCollisionY(Player &p) {
    return mPosition.y >= p.mPosition.y && p.mPosition.y + p.mScale.y >= mPosition.y;
}

bool Finish::checkCollisionX(Player &p) {
    return mPosition.x + mScale.x >= p.mPosition.x && p.mPosition.x + p.mScale.x >= mPosition.x;
}
