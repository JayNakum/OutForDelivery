#pragma once

#include "engine/Renderer.h"
#include "engine/Window.h"
#include "engine/Log.h"

class Application
{
public:
	Application(const char* name);
	~Application();
	void run();

private:
	const char* _name;
	bool _isRunning;
	Window* _window;
	Renderer* _renderer;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
};