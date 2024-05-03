//
// Created by subto on 4/8/2024.
//

#include <iostream>
#include "Window.h"
//#include "glad/glad.h"

void Window::initial() {

    /*glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    windowInstance = glfwCreateWindow(windowWidth, windowHeight, "Window", NULL, NULL);

    if (windowInstance == NULL)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent( windowInstance );

    /*if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        exit(-1);
    }*/

    /*glfwSetFramebufferSizeCallback(windowInstance, framebuffer_size_callback);*/
}
