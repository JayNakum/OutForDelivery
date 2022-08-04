#include "Application.h"

#include "Ground.h"
#include "Package.h"

// settings
const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 600;

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

	Ground ground(shaders);
	Package package(shaders);

	while (_isRunning)
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		_renderer->clear();

		_window->processInputs();
		if (_window->shouldClose()) _isRunning = false;

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		shaders.setMat4("view", view);

		package.render(*_renderer);
		ground.render(*_renderer);

		_window->render(&shaders);
		glfwPollEvents();
	}
}

int main()
{
	Application game("Out For Delivery");
	game.run();
}