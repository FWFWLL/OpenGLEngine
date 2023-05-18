#include "Application.hpp"

#include <GL/gl.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

using namespace FFL;

Application::Application() {

}

Application::~Application() {

}

void Application::run() {
	while(!m_window.shouldClose()) {
		m_window.swapBuffers();

		glfwPollEvents();
	}
}

