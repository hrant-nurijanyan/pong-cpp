#ifndef BEBOP_PONG_PLATFORM_WINDOW_HPP
#define BEBOP_PONG_PLATFORM_WINDOW_HPP

#include <memory>
#include <string>

// Forward declaration so this header does not pull in GLFW.
struct GLFWwindow;

namespace bebop::pong::platform {

struct FramebufferSize {
  int width = 0;
  int height = 0;
};

// Owns a GLFW window with an OpenGL 3.3 core context and loads OpenGL with glad.
// A GLFWLibrary must outlive every Window.
class Window {
 public:
  Window(int width, int height, const std::string& title, bool vsync = true);

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  Window(Window&&) = delete;
  Window& operator=(Window&&) = delete;

  ~Window() = default;

  bool shouldClose() const;
  void close();

  void pollEvents();
  void swapBuffers();

  bool isKeyPressed(int key) const;
  FramebufferSize framebufferSize() const;

  GLFWwindow* handle() const { return m_handle.get(); }

 private:
  struct Deleter {
    void operator()(GLFWwindow* window) const;
  };

  std::unique_ptr<GLFWwindow, Deleter> m_handle;
};

}  // namespace bebop::pong::platform

#endif  // BEBOP_PONG_PLATFORM_WINDOW_HPP
