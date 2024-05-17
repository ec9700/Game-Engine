//
// Created by carson on 4/28/2024.
//

#include "InputManager.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include "vector2.h"
#include "glm/vec2.hpp"

using namespace std;
class InputManager {
    private:
        GLFWwindow* window;
        bool lastInput[GLFW_KEY_LAST]{};
        map<string, vector<int>> keys;
    public:
        //int keyCodeSpace=32;


        InputManager(){

        }
        InputManager(GLFWwindow* window){
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
        glm::vec2 getMousePosition(){
            double mouseX, mouseY;
            glfwGetCursorPos(window, &mouseX, &mouseY);
            auto* returnValue=new glm::vec2(mouseX,mouseY);
            return* returnValue;
        }
        //make a funny wunny mouse controls



        //Ethan Additions
        /**
         * Adds a @p keyCode with name @p keyName to @ref key
         * @param keyName @ref std::string Name to assign keycode
         * @param keyCode @ref int Keycode of key
         * @see ::setKeyMap(std::string, std::vector<int>)
         */
        void addKeyToMap(std::string keyName, int keyCode) {
            keys[keyName].push_back(keyCode);
        }

        /**
         * Checks if a button with a name of @p keyName is currently held down
         * @param keyName @ref std::string Name of key assigned by @ref ::setKeyMap(std::string, std::vector<int>)
         * @return @ref bool True if key is held down, otherwise false
         */
        bool getInput(std::string keyName) {
            if(getFirstKeyHeldInMap(keyName)) return true;
            return false;
        }

        /**
         * Gets a direction based on which key is pressed on an axis
         * @param negativeKeyCode @ref int Negative direction key code
         * @param positiveKeyCode @ref int Positive direction key code
         * @return @ref bool 1 if @p positiveKeyCode is held down, -1 if @p negativeKeyCode is held down, otherwise 0
         */
        int getInputDirection(int negativeKeyCode, int positiveKeyCode) {
            //fixme Apparently the axes are inverted, positive being negative and negative being positive.
            if(getInput(positiveKeyCode) ) return 1;
            if(getInput(negativeKeyCode) ) return -1;
            return 0;
        }

        /**
         * Gets a direction based on which key is pressed on an axis
         * @param negativeKeyName @ref int Negative direction key name
         * @param positiveKeyName @ref int Positive direction key name
         * @return @ref bool 1 if @p positiveKeyName is held down, -1 if @p negativeKeyName is held down, otherwise 0
         */
        int getInputDirection(std::string negativeKeyName, std::string positiveKeyName) {
            return getInputDirection(getFirstKeyHeldInMap(negativeKeyName),
                                     getFirstKeyHeldInMap(positiveKeyName));
        }

        /**
         * Gets a 2D direction based on which keys are pressed on axes in a 2D plane
         * @param negativeKeyCodeX @ref int Negative X direction keycode
         * @param positiveKeyCodeX @ref int Positive X direction keycode
         * @param negativeKeyCodeY @ref int Negative Y direction keycode
         * @param positiveKeyCodeY @ref int Positive Y direction keycode
         * @return @ref glm::vec2 2D direction
         * @see ::getInputDirection(int, int)
         */
        glm::vec2 getInputDirectionVector2(int negativeKeyCodeX, int positiveKeyCodeX, int negativeKeyCodeY, int positiveKeyCodeY) {
            return glm::vec2(getInputDirection(negativeKeyCodeX,positiveKeyCodeX),
                           getInputDirection(negativeKeyCodeY,positiveKeyCodeY));
        }

    /**
     * Gets a 2D direction based on which keys are pressed on axes in a 2D plane
     * @param negativeKeyCodeX @ref int Negative X direction key name
     * @param positiveKeyCodeX @ref int Positive X direction key name
     * @param negativeKeyCodeY @ref int Negative Y direction key name
     * @param positiveKeyCodeY @ref int Positive Y direction key name
     * @return @ref glm::vec2 2D direction
     * @see ::getInputDirection(string, string)
     */
    glm::vec2 getInputDirectionVector2(std::string negativeKeyNameX, std::string positiveKeyNameX, std::string negativeKeyNameY, std::string positiveKeyNameY) {
        return glm::vec2(getInputDirection(negativeKeyNameX,positiveKeyNameX),
                       getInputDirection(negativeKeyNameY,positiveKeyNameY));
    }

private:
    /**
     * @param keyName @ref std::string Name of key to check
     * @return @ref int Keycode of first key in keys[keyName], otherwise 0
     */
    int getFirstKeyHeldInMap(std::string keyName) {
            for(int keyCode : keys[keyName]) {
                if(getInput(keyCode)) return keyCode;
            }
            return 0;
        }



}; // InputManager
