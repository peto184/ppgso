//
// Created by peto184 on 26-Oct-17.
//

#include "camera.h"

Camera::Camera(float fow, float ratio, float near, float far) {
    float fowInRad = ((float)M_PI/180.0f) * fow;

    projectionMatrix = glm::perspective(fowInRad, ratio, near, far);
}

void Camera::update(Scene & scene) {
    Player &p = *scene.mPlayer;

    if(mSwitchCamera){
        mCameraMode = static_cast<CameraMode>((mCameraMode + 1) % (FIRST_PERSON + 1));
        mSwitchCamera = false;
    }

    this->position = p.mPosition;
    switch (mCameraMode) {
        case SIDE_CAMERA:
            this->position.z = +15.0f;
            viewMatrix = lookAt(position, p.mPosition, up);
            break;
        case BEHIND_CAMERA:
            this->position.x -= 10.0f;
            this->position.y += 5.0f;
            viewMatrix = lookAt(position, p.mPosition, up);
            break;
        case FIRST_PERSON:
            if (p.mOrientation == LEFT)
                viewMatrix = lookAt(position + vec3{0.0f, 1.0f, 0.0f}, p.mPosition + vec3{-10.0f,+0.0f,0.0f}, up);
            else
                viewMatrix = lookAt(position + vec3{0.0f, 1.0f, 0.0f}, p.mPosition + vec3{+10.0f,+0.0f,0.0f} , up);
            break;
        default:
            cerr << "Camera mode error." << endl;
    }

}
