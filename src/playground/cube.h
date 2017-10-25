//
// Created by peto184 on 24-Oct-17.
//

#ifndef PPGSO_CUBE_H
#define PPGSO_CUBE_H


#include <cmake-build-debug/shaders/texture_frag_glsl.h>
#include <cmake-build-debug/shaders/texture_vert_glsl.h>
#include <shader.h>
#include <mesh.h>

class Cube {
private:
    ppgso::Texture cubeTexture = ppgso::Texture(0, 0);
    ppgso::Mesh mesh = ppgso::Mesh("cube.obj");

public:

    glm::mat4 modelMatrix;

    Cube(ppgso::Texture cubeTexture, ppgso::Mesh mesh);
    ppgso::Texture getTexture();
    ppgso::Mesh getMesh();
};


#endif //PPGSO_CUBE_H
