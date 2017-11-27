//
// Created by peter on 27-Nov-17.
//

#include "finish.h"

std::unique_ptr<ppgso::Mesh> Finish::mMesh;
std::unique_ptr<ppgso::Shader> Finish::mShader;
std::unique_ptr<ppgso::Texture> Finish::mTexture;

Finish::Finish() {
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("blocks/lapis.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("sphere.obj");
}

bool Finish::update(float time) {
    mModelMatrix = glm::scale(mat4(1.0f), mScale);
    mModelMatrix = glm::translate(mModelMatrix, mPosition);
    mModelMatrix = glm::rotate(mModelMatrix, (float) glfwGetTime() , mRotation);
    return false;
}

void Finish::render(Scene &scene) {
    (*mShader).use();

    // use mCamera
    (*mShader).setUniform("ProjectionMatrix", (*scene.mCamera).projectionMatrix);
    (*mShader).setUniform("ViewMatrix", (*scene.mCamera).viewMatrix);

    // render mesh
    (*mShader).setUniform("ModelMatrix", mModelMatrix);
    (*mShader).setUniform("Texture", *mTexture);
    (*mMesh).render();
}

void Finish::generateModelMatrix() {
    mModelMatrix = glm::translate(mat4{1.0f}, mPosition)
                   * glm::orientate4(mRotation)
                   * glm::scale(mat4(1.0f), mScale);
}
