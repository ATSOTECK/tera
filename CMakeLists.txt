cmake_minimum_required(VERSION 3.17)
project(tera)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc/GLFW)
include_directories(inc/glm)
include_directories(inc/glm/detail)
include_directories(inc/glm/ext)
include_directories(inc/glm/gtc)
include_directories(inc/glm/gtx)
include_directories(inc/glm/simd)
include_directories(inc/KHR)
include_directories(inc/vulkan)
include_directories(src)

include_directories(${PROJECT_SOURCE_DIR}/inc)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(tera
        main.cpp
        src/graphics/vk.cpp
        src/graphics/vk.h
        src/config.h
        src/vec.h
        src/world/block.cpp src/world/block.hpp)

target_link_libraries(tera vulkan-1)
target_link_libraries(tera glfw3)
target_link_libraries(tera freetype)
target_link_libraries(tera spdlog)