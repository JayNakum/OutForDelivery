#pragma once

#include "engine/Renderer.h"

class Package
{
public:
	Package();
    void render(Renderer& renderer);
private:
    float _vertices[12] = {
         0.1f,  0.1f, 0.0f,  // top right
         0.1f, -0.1f, 0.0f,  // bottom right
        -0.1f, -0.1f, 0.0f,  // bottom left
        -0.1f,  0.1f, 0.0f   // top left 
    };
    unsigned int _indices[6] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
	unsigned int VAO, VBO, EBO;
};