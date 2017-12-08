//
// Created by peto184 on 05-Nov-17.
//

#include <cmake-build-debug/shaders/color_vert_glsl.h>
#include <cmake-build-debug/shaders/color_frag_glsl.h>
#include "projectile.h"


std::unique_ptr<ppgso::Mesh> Projectile::mMesh;
std::unique_ptr<ppgso::Shader> Projectile::mShader;
std::unique_ptr<ppgso::Texture> Projectile::mTexture;

Projectile::Projectile(vec3 playerPosition, Orientation orientation) {
    mPosition = playerPosition;
    mPosition.y += .75;
    mOrientation = orientation;

    if (!mShader) mShader = std::make_unique<ppgso::Shader>(color_vert_glsl, color_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("blocks/lapis.bmp"));
    if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("sphere.obj");

    float r = rand() / float(RAND_MAX);
    float g = rand() / float(RAND_MAX);
    float b = rand() / float(RAND_MAX);

    mColor = {r,g,b};
}

bool Projectile::checkCollisionY(Cube& c){
    return mPosition.y >= c.mPosition.y && c.mPosition.y + c.mScale.y >= mPosition.y;
}

bool Projectile::checkCollisionX(Cube& c){
    return mPosition.x + mScale.x >= c.mPosition.x && c.mPosition.x + c.mScale.x >= mPosition.x;
}

bool Projectile::update(Scene &scene, float dt) {
    age += dt;
    if (age > MAX_AGE)
        return false;

    if (mOrientation == LEFT)
        mPosition.x -= dt * PROJECTILE_SPEED;
    else
        mPosition.x += dt * PROJECTILE_SPEED;

    for (Cube c : scene.mCubes) {
        // Check collision only if player is falling
        if (checkCollisionY(c) && checkCollisionX(c)) {
            return false;
        }
    }

    y_speed += PROJECTILE_WEIGHT * dt;
    mPosition.y -= y_speed;

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

    //(*mShader).setUniform("Texture", *mTexture);
    //(*mShader).setUniform("OverallColor", {sin(glfwGetTime()*4), 0.25 + age/MAX_AGE/2, cos(glfwGetTime()*4)});
    (*mShader).setUniform("OverallColor", mColor);



    (*mMesh).render();
}

Projectile::Projectile() {

}
