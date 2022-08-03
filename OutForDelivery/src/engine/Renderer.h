#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Shader.h"

class Renderer
{
public:
	void clear() const;
	void render(const unsigned int& VBO, const unsigned int& EBO) const;
};