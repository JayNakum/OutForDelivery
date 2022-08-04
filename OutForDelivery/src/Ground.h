#pragma once

#include "engine/Renderer.h"

class Ground
{
public:
    Ground(Shader shader);
    void render(Renderer& renderer);

    inline float getTop() { return (translation.y + height); }

    glm::vec3 translation = glm::vec3(-2.0f, -1.5f, 0.0f);

private:

    const float height = 0.5f;
    const float width = 10.0f;


    float _vertices[20] = {
        // positions         // texture coords
        width, height, 0.0f, 1.0f, 1.0f, // top right
        width, 0.0f,   0.0f, 1.0f, 0.0f, // bottom right
         0.0f, 0.0f,   0.0f, 0.0f, 0.0f, // bottom left
         0.0f, height, 0.0f, 0.0f, 1.0f  // top left 
    };
    unsigned int _indices[6] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VAO, VBO, EBO;

    unsigned int texture = 0;
    void initTextures();

    Shader m_shader;
};

