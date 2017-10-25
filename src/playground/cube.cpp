//
// Created by peto184 on 24-Oct-17.
//

#include "cube.h"

std::unique_ptr<ppgso::Mesh> mMesh;
std::unique_ptr<ppgso::Shader> mShader;
std::unique_ptr<ppgso::Texture> mTexture;

Cube::Cube() {
    // Initialize static resources if needed
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("sphere.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("cube.obj");
}
