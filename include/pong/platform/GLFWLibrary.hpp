#ifndef BEBOP_PONG_PLATFORM_GLFWLIBRARY_HPP
#define BEBOP_PONG_PLATFORM_GLFWLIBRARY_HPP

namespace bebop::pong::platform {

class GLFWLibrary {
 public:
  GLFWLibrary();

  GLFWLibrary(const GLFWLibrary&) = delete;
  GLFWLibrary& operator=(const GLFWLibrary&) = delete;

  GLFWLibrary(GLFWLibrary&&) = delete;
  GLFWLibrary& operator=(GLFWLibrary&&) = delete;

  ~GLFWLibrary();

 private:
  static void errorCallback(int code, const char* description);
};
}  // namespace bebop::pong::platform

#endif  // BEBOP_PONG_PLATFORM_GLFWLIBRARY_HPP