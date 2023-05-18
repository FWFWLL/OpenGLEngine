#ifndef FFL_WINDOW
#define FFL_WINDOW

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdint>
#include <string>

namespace FFL {

class Window {
private:
	static void framebufferResizeCallback(GLFWwindow* p_window, int p_w, int p_h);
public:
	Window(uint32_t p_w, uint32_t p_h, std::string p_title);
	~Window();

	// Delete copy-constructors
	Window(const Window&) = delete;
	Window& operator =(const Window&) = delete;
private:
	uint32_t m_width;
	uint32_t m_height;

	bool m_framebufferResized = false;

	std::string m_title;

	GLFWwindow* m_window;

	void initWindow();
	void initOpenGL();
public:
	bool shouldClose() {return glfwWindowShouldClose(m_window);}
	void swapBuffers() {glfwSwapBuffers(m_window);}
};

}

#endif

