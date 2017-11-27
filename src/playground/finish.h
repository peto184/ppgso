//
// Created by peter on 27-Nov-17.
//

#ifndef PPGSO_FINISH_H
#define PPGSO_FINISH_H


#include <mesh.h>
#include <glm/vec3.hpp>

class Scene;
#include "scene.h"

class Finish {
private:
    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;

    void generateModelMatrix();

public:
    Finish ();

    glm::vec3 mPosition{0,0,0};
    glm::vec3 mRotation{1.0,1.0,1.0};
    glm::vec3 mScale{.5f,1.0f,.5f};
    glm::mat4 mModelMatrix{1};

    bool update(float time);
    void render(Scene &scene);
};


#endif //PPGSO_FINISH_H
