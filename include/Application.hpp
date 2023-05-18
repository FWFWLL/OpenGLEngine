#ifndef FFL_APPLICATION
#define FFL_APPLICATION

#include "Engine/Window.hpp"

namespace FFL {

class Application {
private:
	static constexpr uint32_t SCREEN_WIDTH = 800;
	static constexpr uint32_t SCREEN_HEIGHT = 640;
	inline static const std::string APPLICATION_TITLE = "OpenGLEngine";
public:
	Application();
	~Application();

	Application(const Application&) = delete;
	Application& operator =(const Application&) = delete;
private:
	Window m_window = {SCREEN_WIDTH, SCREEN_HEIGHT, APPLICATION_TITLE};
public:
	void run();
};

}

#endif

