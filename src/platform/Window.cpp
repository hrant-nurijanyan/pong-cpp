#include "pong/platform/Window.hpp"

// glad must be included before GLFW.
#include <glad/glad.h>
// Keep this line break so clang-format does not reorder the two includes.
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <string>

namespace bebop::pong::platform {

void Window::Deleter::operator()(GLFWwindow* window) const { glfwDestroyWindow(window); }

Window::Window(int width, int height, const std::string& title, bool vsync) {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

  m_handle.reset(glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr));
  if (!m_handle) {
    throw std::runtime_error("glfwCreateWindow failed");
  }

  glfwMakeContextCurrent(m_handle.get());
  glfwSwapInterval(vsync ? 1 : 0);

  // If this throws, m_handle is already constructed, so the window is still destroyed.
  if (gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0) {
    throw std::runtime_error("Failed to load OpenGL functions with glad");
  }
}

bool Window::shouldClose() const { return glfwWindowShouldClose(m_handle.get()) == GLFW_TRUE; }

void Window::close() { glfwSetWindowShouldClose(m_handle.get(), GLFW_TRUE); }

void Window::pollEvents() { glfwPollEvents(); }

void Window::swapBuffers() { glfwSwapBuffers(m_handle.get()); }

bool Window::isKeyPressed(int key) const { return glfwGetKey(m_handle.get(), key) == GLFW_PRESS; }

FramebufferSize Window::framebufferSize() const {
  FramebufferSize size;
  glfwGetFramebufferSize(m_handle.get(), &size.width, &size.height);
  return size;
}

}  // namespace bebop::pong::platform
