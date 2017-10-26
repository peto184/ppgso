//
// Created by peto184 on 26-Oct-17.
//

#ifndef PPGSO_CAMERA_H
#define PPGSO_CAMERA_H

#include <memory>
#include <glm/glm.hpp>
#include<ppgso/ppgso.h>

class Camera {
public:
    glm::vec3 up{0,1,0};
    glm::vec3 position{0,0,0};
    glm::vec3 back{0,0,-1};

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    /*!
     * Create new Camera that will generate viewMatrix and projectionMatrix based on its position, up and back vectors
     * @param fow - Field of view in degrees
     * @param ratio - Viewport screen ratio (usually width/height of the render window)
     * @param near - Distance to the near frustum plane
     * @param far - Distance to the far frustum plane
     */
    explicit Camera(float fow = 45.0f, float ratio = 1.0f, float near = 0.1f, float far = 10.0f);

    /*!
     * Update Camera viewMatrix based on up, position and back vectors
     */
    void update();
};


#endif //PPGSO_CAMERA_H