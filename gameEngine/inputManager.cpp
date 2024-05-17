//
// Created by carson on 4/28/2024.
//

#include "inputManager.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include "vector2.h"
using namespace std;
class inputManager {
    private:
        GLFWwindow* window;
        bool lastInput[GLFW_KEY_LAST]{};
        map<string, vector<int>> keys;
    public:
        int keyCodeSpace=32;


        inputManager(){

        }
        inputManager(GLFWwindow* window){
            this->window=window;
        }
        void setKeyMap(string name,vector<int> id){
            keys[name]=std::move(id);
        }
        bool getKeyMap(string name){
            vector inputKeys=keys[name];
            for(int i=0;i<inputKeys.size();i++)
            {
                if(getInput(inputKeys[i]))
                {
                    return true;
                }
            }
            return false;
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
        void setWindow(GLFWwindow* windowInstance)
        {
            window=windowInstance;
        }
        void lockMouse(bool shouldLock){
            if(shouldLock) {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            }
            else
            {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        }
        vector2 getMousePosition(){
            double mouseX, mouseY;
            glfwGetCursorPos(window, &mouseX, &mouseY);
            auto* returnValue=new vector2(mouseX,mouseY);
            return* returnValue;
        }
        //make a funny wunny mouse controls

}; // inputManager
