//
// Created by peter on 27-Nov-17.
//

#ifndef PPGSO_FINISH_H
#define PPGSO_FINISH_H


#include <mesh.h>
#include <glm/vec3.hpp>

class Scene;
#include "scene.h"

#include <cmake-build-debug/shaders/diffuse_vert_glsl.h>
#include <cmake-build-debug/shaders/diffuse_frag_glsl.h>

class Finish {
private:
    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;

    bool checkCollisionY(Player& p);

    bool checkCollisionX(Player& p);

public:
    Finish ();

    glm::vec3 mPosition{0,0,0};
    glm::vec3 mRotation{0.0,1.0,0.0};
    glm::vec3 mScale{0.5f,1.5f,0.5f};
    glm::mat4 mModelMatrix{1};

    bool update(Scene &scene, float time);
    void render(Scene &scene);
};


#endif //PPGSO_FINISH_H
