add_library(pong_glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)

target_include_directories(pong_glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
