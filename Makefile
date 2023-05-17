CFLAGS := -std=c++17 -Iinclude
LDFLAGS = -lglfw

all: src/*.cpp src/**/*.cpp
	g++ $(CFLAGS) -o bin/VulkanEngine src/*.cpp src/**/*.cpp $(LDFLAGS)

.PHONY: run clean

run:
	@./bin/VulkanEngine

clean:
	@rm -f bin/VulkanEngine

