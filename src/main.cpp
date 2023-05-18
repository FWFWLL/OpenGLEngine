#include "Application.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace FFL;

int main(int argc, char** argv) {
	Application app{};

	try {
		app.run();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

