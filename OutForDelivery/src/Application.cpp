#include "Application.h"
#include <cstdlib>
#include "Ground.h"
#include "Store.h"
#include "House.h"
#include "Cannon.h"
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
	bool canShoot = true;
	bool reset = true;
	srand(time(0));
	Shader shaders("res\\shaders\\3.3.shader.vs", "res\\shaders\\3.3.shader.fs");
	Ground ground(shaders);
	Store store(shaders);
	House house(shaders);
	Cannon cannon(shaders);
	Package package(shaders);

	glm::mat4 projection = glm::mat4(1.0f);
	// projection = glm::perspective(glm::radians(45.0f), (float)_width / (float)_height, 0.1f, 100.0f);
	projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
	shaders.setMat4("projection", projection);
	glm::vec3 camera = glm::vec3(0.0f, 0.0f, -3.0f);

	while (_isRunning)
	{
		if (reset)
		{
			camera = glm::vec3(0.0f, 0.0f, -3.0f);
			reset = false;
		}
		
		_renderer->clear();
		
		if (_window->shouldClose()) _isRunning = false;

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, camera);
		shaders.setMat4("view", view);

		ground.render(*_renderer);
		store.render(*_renderer);
		cannon.render(*_renderer);
		house.render(*_renderer);
		package.render(*_renderer, camera);
		if (_window->isPressed(GLFW_KEY_UP))
		{
			if(cannon.angle < 90.0f)
				cannon.angle += 1.0f;
		}
		if (_window->isPressed(GLFW_KEY_DOWN))
		{
			if (cannon.angle > 0.0f)
				cannon.angle -= 1.0f;
		}
		if (_window->isPressed(GLFW_KEY_SPACE) && canShoot)
		{
				package.shoot(cannon.power, cannon.angle / 100);
				canShoot = false;			
		}
		if (_window->isPressed(GLFW_KEY_R) && !reset)
		{
			if (package.getPos() >= house.getPos() - 1.0f && package.getPos() <= house.getPos() + 1.0f)
			{
				house.reset((rand() % 10) + 2);

			}
			package.reset();
			reset = true;
			canShoot = true;
		}
		
		_window->render();
		glfwPollEvents();
	}
}

int main()
{
	Application game("Out For Delivery");
	game.run();
}