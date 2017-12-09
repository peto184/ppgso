//
// Created by peto184 on 08-Dec-17.
//

#ifndef PPGSO_ENEMY_H
#define PPGSO_ENEMY_H

#include <ppgso.h>

#include "object.h"
#include "movable.h"

class Enemy final : public Object, public Movable {
public:
    Enemy();

    bool update(Scene &scene, float time) override;
    void render(Scene &scene) override;

private:
    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;
};


#endif //PPGSO_ENEMY_H
