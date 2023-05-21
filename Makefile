TARGET := bin/OpenGLEngine

CFLAGS := -std=c++17 -m64 -Iinclude -Ideps/include
LDFLAGS := -lglfw -lGL

all: $(TARGET)

$(TARGET):
	g++ $(CFLAGS) -o $@ src/*.cpp src/**/*.cpp deps/src/glad.c $(LDFLAGS)

.PHONY: run clean

run: all
	@./$(TARGET)

clean: $(TARGET)
	@rm -rf $(TARGET)

