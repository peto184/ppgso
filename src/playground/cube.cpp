//
// Created by peto184 on 24-Oct-17.
//
#include "cube.h"

std::unique_ptr<ppgso::Mesh> Cube::mMesh;
std::unique_ptr<ppgso::Shader> Cube::mShader;
std::unique_ptr<ppgso::Texture> Cube::mTexture;

Cube::Cube(){
    // Initialize static resources if needed
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("blocks/stonebrick.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("cube.obj");
}

bool Cube::update(float time) {
    mModelMatrix = glm::scale(mat4(1.0f), mScale);
    mModelMatrix = glm::translate(mModelMatrix, mPosition);
    mModelMatrix = glm::rotate(mModelMatrix, 0.0f, mRotation);
    //generateModelMatrix();

    return true;
}

void Cube::render(Scene &scene) {
    (*mShader).use();

    // use mCamera
    (*mShader).setUniform("ProjectionMatrix", (*scene.mCamera).projectionMatrix);
    (*mShader).setUniform("ViewMatrix", (*scene.mCamera).viewMatrix);

    // render mesh
    (*mShader).setUniform("ModelMatrix", mModelMatrix);
    (*mShader).setUniform("Texture", *mTexture);
    (*mMesh).render();
}

void Cube::generateModelMatrix() {
    mModelMatrix = glm::translate(mat4{1.0f}, mPosition)
            * glm::orientate4(mRotation)
            * glm::scale(mat4(1.0f), mScale);
}