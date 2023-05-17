#ifndef FFL_APPLICATION
#define FFL_APPLICATION

#include "Engine/Window.hpp"

using namespace FFL;

class Application {
private:
	static constexpr uint32_t SCREEN_WIDTH = 800;
	static constexpr uint32_t SCREEN_HEIGHT = 800;
public:
	Application();
	~Application();

	Application(const Application&) = delete;
	Application& operator =(const Application&) = delete;
private:
	Window m_window{SCREEN_WIDTH, SCREEN_HEIGHT, "VulkanEngine"};
public:
	void run();
};

#endif

