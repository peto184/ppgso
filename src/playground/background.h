//
// Created by peto184 on 27-Oct-17.
//

#ifndef PPGSO_BACKGROUND_H
#define PPGSO_BACKGROUND_H

class Scene;
#include "scene.h"

#include <glm/glm.hpp>
#include <ppgso.h>

class Background {
public:
    Background();

    glm::vec3 mPosition{0.0, 0.0, 0.0};
    glm::vec3 mRotation{1.0,1.0,1.0};
    glm::vec3 mScale{1.0,1.0,1.0};

    glm::mat4 mModelMatrix{1};

    glm::vec2 mTextureOffset;

    bool update(Scene& scene, float dt);
    void render(Scene &scene);

private:
    static std::unique_ptr<ppgso::Mesh> mMesh;
    static std::unique_ptr<ppgso::Shader> mShader;
    static std::unique_ptr<ppgso::Texture> mTexture;
};


#endif //PPGSO_BACKGROUND_H
