#pragma once
#include "engine/Renderer.h"

class Cannon
{
public:
    Cannon(Shader& shader);
    void render(Renderer& renderer);

    float power = 0.03f; 
    float angle = 40.0f;
private:

    float _vertices[20] = {
        // positions        // texture coords
         0.3f,  0.15f, 0.0f, 1.0f, 1.0f, // top right
         0.3f, -0.10f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.3f, -0.10f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.3f,  0.15f, 0.0f, 0.0f, 1.0f  // top left 
    };
    unsigned int _indices[6] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VAO, VBO, EBO;

    unsigned int texture = 0;
    void initTextures();

    glm::vec3 translation = glm::vec3(0.0f, -0.9f, 0.0f);

    Shader m_shader;

};