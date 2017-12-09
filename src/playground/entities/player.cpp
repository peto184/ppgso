//
// Created by peto184 on 26-Oct-17.
//

#include "player.h"

ppgso::Mesh* Player::mMesh;

std::unique_ptr<ppgso::Mesh> Player::mMeshJumping;
std::unique_ptr<ppgso::Mesh> Player::mMeshStanding;

std::unique_ptr<ppgso::Shader> Player::mShader;
std::unique_ptr<ppgso::Texture> Player::mTexture;

Player::Player(){
    if (!mShader) mShader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!mTexture) mTexture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("psyduck/psyduck2.bmp"));
    //if (!mMesh) mMesh = std::make_unique<ppgso::Mesh>("Arnold_T-850/arnold_jumping.obj");

    if (!mMeshStanding) mMeshStanding = std::make_unique<ppgso::Mesh>("psyduck/psyduck2.obj");
    if (!mMeshJumping) mMeshJumping = std::make_unique<ppgso::Mesh>("psyduck/psyduck1.obj");
    if (!mMesh) mMesh = mMeshStanding.get();

    mOrientation = RIGHT;
    mPosition = {0.0, 1.0, 0.0};
    mScale = {1.0, 1.0, 1.0};
    mDirection = {0.0, 0.0, 0.0};
    mRotation = {0.0, 1.0, 0.0};
}

bool Player::update(Scene &scene, float dt) {

    // === Set directions
    if(scene.keyboard[GLFW_KEY_A]){
        mDirection.x = -SPEED;
        mRotAngle = (float) (M_PI / 2.0);
        mOrientation = LEFT;
    }
    else if (scene.keyboard[GLFW_KEY_D]) {
        mDirection.x = +SPEED;
        mRotAngle = (float) (3 * M_PI / 2.0);
        mOrientation = RIGHT;
    }
    else {
        mDirection.x = 0;
    }
    if (scene.keyboard[GLFW_KEY_W] && mPlayerState == PLAYER_ON_GROUND){
        mDirection.y = JUMP_STRENGHT;
        mPlayerState = PLAYER_IN_AIR;
        mMesh = mMeshJumping.get();
    }

    if (scene.keyboard[GLFW_KEY_SPACE] && mReload > RELOAD_TIME){
        auto p = make_unique<Projectile>(this->mPosition, this->mOrientation);
        scene.mProjectiles.push_back(move(p));
        mReload = 0.0f;
    }

    if (mReload < RELOAD_TIME)
        mReload += dt;

    // Gravity
    if (mDirection.y > -GRAVITY)
        mDirection.y -= GRAVITY*dt;

    for (Cube &c : scene.mCubes) {
        // Check collision only if player is falling
        vec3 dist(glm::distance(mPosition, c.mPosition));

        if (dist.y < c.mScale.y && dist.x < c.mScale.x && mDirection.y < 0) {
            mPosition.y = c.mPosition.y + c.mScale.y/2.0f;

            if (mDirection.y < 0.0)
                mDirection.y = 0.0f;

            mMesh = mMeshStanding.get();
            mPlayerState = PLAYER_ON_GROUND;
            break;
        }
    }

    for (auto &e : scene.mEnemies){
        vec3 dist(glm::distance(mPosition, e->mPosition));
        if (dist.y < e->mScale.y && dist.x < e->mScale.x){
            scene.resetLevel = true;
        }
    }


    //cout << mPosition.x << "\t" << mPosition.y << "\t" << mDirection.y << endl;

    // Move from position by direction in dt
    mPosition = mPosition + (mDirection*dt);
    mModelMatrix = glm::translate(mat4(1.0f), mPosition)
                        * glm::rotate(mat4(1.0f), mRotAngle, mRotation)
                        * glm::scale(mat4(1.0f), mScale);


    if (mPosition.y < -10.0){
        scene.resetLevel = true;
    }

    return true;
}

void Player::render(Scene &scene) {
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
