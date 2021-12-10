#include <iostream>

#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow *window = glfwCreateWindow(800, 600, "tera", nullptr, nullptr);
    //glfwSetFramebufferSizeCallback(window, vkResize);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
