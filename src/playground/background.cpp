//
// Created by peto184 on 27-Oct-17.
//

#include "background.h"

std::unique_ptr<ppgso::Mesh> Background::mMesh;
std::unique_ptr<ppgso::Shader> Background::mShader;
std::unique_ptr<ppgso::Texture> Background::mTexture;

Background::Background(){
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("background.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("quad.obj");
}


bool Background::update(Scene &scene, float dt) {
    mTextureOffset.x -= dt/20.0f;
    mModelMatrix = glm::translate(mat4(1.0f), mPosition)
                   * glm::rotate(mat4(1.0f), 0.0f, mRotation)
                   * glm::scale(mat4(1.0f), mScale);
    return false;
}

void Background::render(Scene &scene) {
    // Disable writing to the depth buffer so we render a "background"
    glDepthMask(GL_FALSE);

    // NOTE: this object does not use camera, just renders the entire quad as is
    (*mShader).use();

    // Pass UV mapping offset to the shader
    (*mShader).setUniform("TextureOffset", mTextureOffset);

    // Render mesh, not using any projections, we just render in 2D
    (*mShader).setUniform("ModelMatrix", mModelMatrix);
    (*mShader).setUniform("ViewMatrix", mat4{});
    (*mShader).setUniform("ProjectionMatrix", mat4{});
    (*mShader).setUniform("Texture", *mTexture);
    (*mMesh).render();

    glDepthMask(GL_TRUE);
}
