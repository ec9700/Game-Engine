//
// Created by carson on 4/28/2024.
//

#include "inputManager.h"
#include "GLFW/glfw3.h"
class inputManager {
    private:
        GLFWwindow* window;
    public:
        int keyCodeSpace=32;

        inputManager(GLFWwindow* window){
            this->window=window;

        }
        int getKeyCode(char character){
            return (int)character;
        }
        bool getInputPressed(int keyCode){
            return glfwGetKey(window,keyCode)==GLFW_PRESS;
        }
}; // inputManager
