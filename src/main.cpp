#include <glad/glad.h>
// glad must be included before GLFW.
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <exception>
#include <iostream>

#include "pong/platform/GLFWLibrary.hpp"
#include "pong/platform/Window.hpp"

int main() {
  using bebop::pong::platform::GLFWLibrary;
  using bebop::pong::platform::Window;

  try {
    GLFWLibrary glfw;
    Window window(1280, 720, "Pong");

    while (!window.shouldClose()) {
      window.pollEvents();

      if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
        window.close();
      }

      const auto [width, height] = window.framebufferSize();
      glViewport(0, 0, width, height);
      glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      window.swapBuffers();
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
