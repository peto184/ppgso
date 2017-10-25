//
// Created by peto184 on 24-Oct-17.
//

#include "cube.h"

Cube::Cube(ppgso::Texture cubeTexture, ppgso::Mesh mesh) {
    this->cubeTexture = cubeTexture;
    this->mesh = mesh;
}

ppgso::Texture Cube::getTexture() {
    return cubeTexture;
}

ppgso::Mesh Cube::getMesh() {
    return mesh;
}
