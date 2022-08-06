#pragma once

#include "engine/Renderer.h"

class Package
{
public:
	Package(Shader& shader);
    void render(Renderer& renderer, glm::vec3&);
    void shoot(float power, float angle);
    inline float getPos() { return translation.x; }
    void reset();
private:
    float yVelocity = 0.0f;
    float xVelocity = 0.001f;
    bool fire = false;
    float rotation = 0.0f;

    float _vertices[20] = {
        // positions        // texture coords
         0.15f,  0.1f, 0.0f, 1.0f, 1.0f, // top right
         0.15f, -0.1f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.15f, -0.1f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.15f,  0.1f, 0.0f, 0.0f, 1.0f  // top left 
    };
    unsigned int _indices[6] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
	unsigned int VAO, VBO, EBO;
    
    unsigned int texture = 0;
    void initTextures();
    
    glm::vec3 translation = glm::vec3(-0.1f, -0.9f, 0.0f);

    Shader m_shader;

};