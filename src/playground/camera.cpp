//
// Created by peto184 on 26-Oct-17.
//

#include "camera.h"

Camera::Camera(float fow, float ratio, float near, float far) {
    float fowInRad = ((float)M_PI/180.0f) * fow;

    projectionMatrix = glm::perspective(fowInRad, ratio, near, far);
}

void Camera::update() {
    viewMatrix = lookAt(position, position - back, up);
}
