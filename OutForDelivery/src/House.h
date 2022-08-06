#pragma once
#include "engine/Renderer.h"

class House
{
public:
    House(Shader& shader);
    void render(Renderer& renderer);
    void reset(float newPos);
    inline float getPos() { return translation.x; }
private:

    float _vertices[20] = {
        // positions        // texture coords
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left 
    };
    unsigned int _indices[6] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VAO, VBO, EBO;

    unsigned int texture = 0;
    void initTextures();

    glm::vec3 translation = glm::vec3(10.0f, -0.5f, 0.0f);

    Shader m_shader;

};
