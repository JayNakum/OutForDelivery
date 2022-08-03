#pragma once

#include "engine/Renderer.h"

class Package
{
public:
	Package(Shader* shader);
    void render(Renderer& renderer);

    glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);

private:
    float _vertices[20] = {
        // positions        // texture coords
         0.2f,  0.2f, 0.0f, 1.0f, 1.0f, // top right
         0.2f, -0.2f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.2f, -0.2f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.2f,  0.2f, 0.0f, 0.0f, 1.0f  // top left 
    };
    unsigned int _indices[6] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
	unsigned int VAO, VBO, EBO;
    
    unsigned int texture = 0;
    void initTextures();

    Shader* m_shader;

};