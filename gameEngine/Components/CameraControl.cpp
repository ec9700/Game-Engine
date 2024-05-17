//
// Created by subto on 4/8/2024.
//

#include "CameraControl.h"
#include "../GameManager.h"
#include "../inputManager.h"
#include "../inputManager.cpp"
#include "../vector2.h"
#include<math.h>
inputManager input=*new inputManager();
vector2 mousePositionLast=*new vector2(0,0);
double mouseSensitivity=10;
double mouseLimits=80;

void CameraControl::initial(Entity& parent) {

}

void CameraControl::update(Entity &parent, double& deltaTime) {
    //mouse movement
    input.lockMouse(true);
    input.setWindow(GameManager::window.windowInstance);

    auto mousePosition=input.getMousePosition();

    parent.rotation.y+=(mousePosition.x-mousePositionLast.x) * mouseSensitivity * deltaTime;
    parent.rotation.x+=(mousePosition.y-mousePositionLast.y) * mouseSensitivity * deltaTime;

    if(parent.rotation.x<=-mouseLimits)
    {
        parent.rotation.x=-mouseLimits;
    }
    if(parent.rotation.x>=mouseLimits)
    {
        parent.rotation.x=mouseLimits;
    }

    input.setKeyMap("Forward", {input.getKeyCode('W')});

    input.setKeyMap("Backward", {input.getKeyCode('S')});

    input.setKeyMap("Left", {input.getKeyCode('A')});

    input.setKeyMap("Right", {input.getKeyCode('D')});

    input.setKeyMap("Up", {GLFW_KEY_SPACE,GLFW_KEY_ENTER});

    //Camera Movement
    int moveSpeed = 5;

    double xSpeed = cos(parent.rotation.x)*moveSpeed;

    double zSpeed = sin(parent.rotation.x)*moveSpeed;

    if(glfwGetKey(GameManager::window.windowInstance,GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) moveSpeed *= 2;

    if (input.getKeyMap("Right")) {
        parent.position.x -= moveSpeed * deltaTime;
    }
    if (input.getKeyMap("Left")) {
        parent.position.x += moveSpeed * deltaTime;
    }
    if (input.getKeyMap("Forward")) {
        parent.position.z += moveSpeed * deltaTime;
    }
    if (input.getKeyMap("Backward")) {
        parent.position.z -= moveSpeed * deltaTime;
    }
    if (input.getKeyMap("Up")) {
        parent.position.y -= moveSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        parent.position.y += moveSpeed * deltaTime;
    }
    //Reset position
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_P) == GLFW_PRESS) {
        parent.position.x = 0;
        parent.position.y = 0;
        parent.position.z = 0;
    }
    //rest the last mouse position!
    mousePositionLast.x=mousePosition.x;
    mousePositionLast.y=mousePosition.y;
}

void CameraControl::reset(Entity& parent) {

}
