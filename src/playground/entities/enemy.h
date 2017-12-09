//
// Created by peto184 on 08-Dec-17.
//

#ifndef PPGSO_ENEMY_H
#define PPGSO_ENEMY_H

#include "src/playground/scene.h"

class Enemy : public Object {
public:
    Enemy();
    Enemy(const Enemy&) = default;
    Enemy(Enemy&&) = default;

    bool update(Scene &scene, float dt) override;
    void render(Scene &scene) override;

    static const int MAX_HEALTH = 1;
    int mHealth;

    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;
};


#endif //PPGSO_ENEMY_H
