//
// Created by peto184 on 24-Oct-17.
//

#ifndef PPGSO_CUBE_H
#define PPGSO_CUBE_H

#include <ppgso.h>
#include <cmake-build-debug/shaders/texture_frag_glsl.h>
#include <cmake-build-debug/shaders/texture_vert_glsl.h>

#include "object.h"

class Scene;

class Cube : public Object {
private:
    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;

public:
    Cube();

    glm::vec3 mPosition{0,0,0};
    glm::vec3 mRotation{1.0,1.0,1.0};
    glm::vec3 mScale{1,1,1};
    glm::mat4 mModelMatrix{1};

    bool update(Scene& scene, float dt) override;
    void render(Scene &scene) override;
};


#endif //PPGSO_CUBE_H
