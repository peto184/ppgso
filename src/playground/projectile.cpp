//
// Created by peto184 on 05-Nov-17.
//

#include "projectile.h"


std::unique_ptr<ppgso::Mesh> Projectile::mMesh;
std::unique_ptr<ppgso::Shader> Projectile::mShader;
std::unique_ptr<ppgso::Texture> Projectile::mTexture;

bool Projectile::update(Scene &scene, float dt) {
    age += dt;
    if (age > MAX_AGE)
        return false;

    if (mOrientation == LEFT)
        mPosition.x += dt * PROJECTILE_SPEED;
    else
        mPosition.x -= dt * PROJECTILE_SPEED;


    mModelMatrix = glm::translate(mat4(1.0f), mPosition)
                   * glm::rotate(mat4(1.0f), (float) glfwGetTime(), mRotation)
                   * glm::scale(mat4(1.0f), mScale);
    return true;
}

void Projectile::render(Scene &scene) {
    (*mShader).use();

    // use mCamera
    (*mShader).setUniform("ProjectionMatrix", (*scene.mCamera).projectionMatrix);
    (*mShader).setUniform("ViewMatrix", (*scene.mCamera).viewMatrix);

    // render mesh
    (*mShader).setUniform("ModelMatrix", mModelMatrix);
    (*mShader).setUniform("Texture", *mTexture);
    (*mMesh).render();
}

Projectile::Projectile(vec3 playerPosition, Orientation orientation) {
    mPosition = playerPosition;
    mPosition.y += .75;
    mOrientation = orientation;

    if (!mShader) mShader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("blocks/lapis.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("sphere.obj");
}

Projectile::Projectile() {

}
