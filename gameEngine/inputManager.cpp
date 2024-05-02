//
// Created by carson on 4/28/2024.
//

#include "inputManager.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <list>
class inputManager {
    private:
        GLFWwindow* window;
        bool lastInput[GLFW_KEY_LAST]{};
    public:
        int keyCodeSpace=32;

        inputManager(GLFWwindow* window){
            this->window=window;

        }
        int getKeyCode(char character){
            return (int)character;
        }
        bool getInput(int keyCode){
            return glfwGetKey(window,keyCode)==GLFW_PRESS;
        }
        bool getInputJustPressed(int keyCode){
            bool pressed=getInput(keyCode);
            bool returnValue=false;
            if(pressed&&!lastInput[keyCode])
            {
                returnValue=true;
            }
            lastInput[keyCode] = pressed;
            return returnValue;
        }
        bool getInputJustReleased(int keyCode){
            bool pressed=getInput(keyCode);
            bool returnValue=false;
            if(!pressed&&lastInput[keyCode])
            {
                returnValue=true;
            }
            lastInput[keyCode] = pressed;
            return returnValue;
        }

}; // inputManager
