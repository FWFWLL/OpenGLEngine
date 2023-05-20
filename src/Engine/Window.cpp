#include "Engine/Window.hpp"

#include <GL/gl.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

using namespace FFL;

void Window::framebufferResizeCallback(GLFWwindow* p_window, int p_w, int p_h) {
	Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(p_window));
	window->m_framebufferResized = true;
	window->m_width = static_cast<uint32_t>(p_w);
	window->m_height = static_cast<uint32_t>(p_h);
}

Window::Window(uint32_t p_w, uint32_t p_h, std::string p_title) : m_width{p_w}, m_height{p_h}, m_title{p_title} {
	initWindow();
	initOpenGL();
}

Window::~Window() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::initWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
	if(m_window == NULL) {
		throw std::runtime_error("failed to create window!");
	}

	glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
}

void Window::initOpenGL() {
	glfwMakeContextCurrent(m_window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::runtime_error("failed to initialize GLAD!");
	}

	glViewport(0, 0, m_width, m_height);
}

