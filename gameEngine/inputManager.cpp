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
        bool keysHeld[222];
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
        bool getInputPressed(int keyCode){
            bool returnValue=glfwGetKey(window,keyCode)==GLFW_PRESS;
            if(getInputReleased(keyCode))
            {
                keysHeld[keyCode]=false;
            }
            if(keysHeld[keyCode])
            {
                returnValue=false;
            }
            else {
                keysHeld[keyCode] = true;
            }
            return returnValue;
        }
        bool getInputReleased(int keyCode){
            return glfwGetKey(window,keyCode)==GLFW_RELEASE;
        }
}; // inputManager
