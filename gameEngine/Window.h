//
// Created by subto on 4/8/2024.
//

#ifndef GAMELIB_WINDOW_H
#define GAMELIB_WINDOW_H


#include "GLFW/glfw3.h"

class Window {
public:
    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;

    GLFWwindow* windowInstance;

    //fixme Apprently this does nothing. Make it create window
    void initial();
};


#endif //GAMELIB_WINDOW_H
