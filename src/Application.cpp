#include "Application.hpp"

#include <GLFW/glfw3.h>

using namespace FFL;

Application::Application() {

}

Application::~Application() {

}

void Application::run() {
	while(!m_window.shouldClose()) {
		glfwPollEvents();
	}
}

