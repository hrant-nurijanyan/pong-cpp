#include "pong/platform/GLFWLibrary.hpp"

// This file does not use OpenGL, so stop glfw3.h from including the system GL header.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <string>

namespace bebop::pong::platform {

GLFWLibrary::GLFWLibrary() {
  glfwSetErrorCallback(errorCallback);

  if (glfwInit() != GLFW_TRUE) {
    const char* description = nullptr;
    glfwGetError(&description);
    throw std::runtime_error(std::string("glfwInit failed: ") +
                             (description != nullptr ? description : "unknown error"));
  }
}

GLFWLibrary::~GLFWLibrary() {
  glfwTerminate();
  glfwSetErrorCallback(nullptr);
}

void GLFWLibrary::errorCallback(int code, const char* description) {
  std::cerr << "[GLFW] error " << code << ": " << description << '\n';
}

}  // namespace bebop::pong::platform
