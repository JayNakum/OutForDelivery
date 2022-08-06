#include "Renderer.h"

void Renderer::render(const unsigned int& VAO, const unsigned int& EBO) const
{
	glBindVertexArray(VAO);
	// EBO later for size
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::clear() const
{
	glClearColor(0.607f, 0.721f, 0.929f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSwapInterval(1);
}