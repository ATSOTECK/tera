#include <iostream>

#include <GLFW/glfw3.h>

#include "graphics/vk.h"

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow *window = glfwCreateWindow(800, 600, "tera", nullptr, nullptr);
    glfwSetFramebufferSizeCallback(window, vkResize);
    
    Vulkan vk{};
    vk.init(window, VK_DEBUG);
    vk.displayInfo();
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        vk.drawFrame();
    }
    
    vk.wait();
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
