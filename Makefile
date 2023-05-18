TARGET := OpenGLEngine

CFLAGS := -std=c++17 -m64 -Iinclude -Ideps
LDFLAGS := -lglfw -lGL

all: src/*.cpp src/**/*.cpp
	g++ $(CFLAGS) -o bin/$(TARGET) src/*.cpp src/**/*.cpp deps/glad.c $(LDFLAGS)

.PHONY: run clean

run:
	@./bin/$(TARGET)

clean:
	@rm -f bin/$(TARGET)

