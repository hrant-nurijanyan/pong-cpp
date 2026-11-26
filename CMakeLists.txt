cmake_minimum_required(VERSION 3.29)

project(pong-cpp
	VERSION 0.1.0
	DESCRIPTION "A simple multiplayer pong game"
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Third parties
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

# Glad
set(GLAD_DIR ${THIRD_PARTY_DIR}/glad)

add_subdirectory(${GLAD_DIR})

# GLFW (vendored source, 3.5.1)
set(GLFW_DIR ${THIRD_PARTY_DIR}/glfw)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(${GLFW_DIR})

# Game
add_executable(pong-cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/src/platform/GLFWLibrary.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/platform/Window.cpp
)

target_include_directories(pong-cpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(pong-cpp PRIVATE pong_glad glfw)
