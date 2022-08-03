#include "Application.h"
#include "Package.h"

Application::Application(const char* name)
	: _name(name)
{
	_isRunning = true;
	if (!glfwInit())
	{
		ERROR("Failed to initialize GLFW.");
		_isRunning = false;
	}
	_window = new Window(_name, 900, 600);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ERROR("Failed to initialize GLAD.");
	}

	_renderer = new Renderer();
}

Application::~Application()
{
	glfwTerminate();
	delete _window;
	delete _renderer;
}

void Application::run()
{
	Shader shaders("res\\shaders\\3.3.shader.vs", "res\\shaders\\3.3.shader.fs");
	shaders.use();

	Package package;

	while (_isRunning)
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		_renderer->clear();

		_window->processInputs();
		if (_window->shouldClose()) _isRunning = false;

		package.render(*_renderer);

		_window->render();
		glfwPollEvents();
	}
}

int main()
{
	Application game("Out For Delivery");
	game.run();
}