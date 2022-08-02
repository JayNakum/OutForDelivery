#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Log.h"

class Window
{
public:
	Window(const char* title, int width, int height);
	
	void render();
	void processInputs();

	bool shouldClose();
	
	static void callbackResize(GLFWwindow* window, int width, int height);
	bool isFullscreen();
	void setFullScreen(bool fullscreen);

private:
	void resize(int width, int height);

	GLFWwindow* _glfwWindow;
	int _width, _height;
	int _xPos = 0, _yPos = 0;
	int _viewportWidth = 0, _viewportHeight = 0;
	bool _updateViewport = true;
	GLFWmonitor* _monitor;
};

