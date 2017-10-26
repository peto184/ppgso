//
// Created by peto184 on 24-Oct-17.
//

#ifndef PPGSO_CUBE_H
#define PPGSO_CUBE_H

#include <ppgso.h>
#include <cmake-build-debug/shaders/texture_frag_glsl.h>
#include <cmake-build-debug/shaders/texture_vert_glsl.h>

class Scene;
#include "scene.h"

class Cube {
private:
public:
    std::unique_ptr<ppgso::Mesh> mMesh;
    std::unique_ptr<ppgso::Shader> mShader;
    std::unique_ptr<ppgso::Texture> mTexture;

    glm::vec3 mPosition{0,0,0};
    glm::vec3 mRotation{0,0,0};
    glm::vec3 mScale{1,1,1};
    glm::mat4 mModelMatrix{1};

    Cube();

    void update(Scene &scene);
    void render(Scene &scene);
};


#endif //PPGSO_CUBE_H
