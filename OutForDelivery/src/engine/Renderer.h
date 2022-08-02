#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	void clear() const;
	void render(const unsigned int& VBO, const unsigned int& EBO) const;
};