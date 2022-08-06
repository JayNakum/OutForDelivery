#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "Log.h"

class Window
{
public:
	Window(const char* title, int width, int height);
	
	void render();

	bool shouldClose();
	
	static void callbackResize(GLFWwindow* window, int width, int height);
	bool isFullscreen();
	void setFullScreen(bool fullscreen);

	inline bool isPressed(int keyCode) { return (glfwGetKey(_glfwWindow, keyCode) == GLFW_PRESS); }
	inline bool isReleased(int keyCode) { return (glfwGetKey(_glfwWindow, keyCode) == GLFW_RELEASE); }
	
private:
	void resize(int width, int height);

	int _width, _height;
	int _xPos = 0, _yPos = 0;
	int _viewportWidth = 0, _viewportHeight = 0;
	bool _updateViewport = true;
	GLFWmonitor* _monitor;
	GLFWwindow* _glfwWindow;
};

