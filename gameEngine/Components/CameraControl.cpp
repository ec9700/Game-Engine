//
// Created by subto on 4/8/2024.
//

#include "CameraControl.h"
#include "../GameManager.h"
#include "../vector2.h"
//InputManager inputManager=*new InputManager();
vector2 mousePositionLast=*new vector2(0,0);
double mouseSensitivity=10;
double mouseLimits=80;
int moveSpeed = 5;

void CameraControl::initial(Entity& parent) {
    GameManager::inputManager.addKeyToMap("left",GLFW_KEY_A);
    GameManager::inputManager.addKeyToMap("right",GLFW_KEY_D);
    GameManager::inputManager.addKeyToMap("forward",GLFW_KEY_W);
    GameManager::inputManager.addKeyToMap("backward",GLFW_KEY_S);
    GameManager::inputManager.addKeyToMap("up",GLFW_KEY_SPACE);
    GameManager::inputManager.addKeyToMap("down",GLFW_KEY_LEFT_SHIFT);
}

void CameraControl::update(Entity &parent, double& deltaTime) {

    //mouse movement
    GameManager::inputManager.lockMouse(true);
    GameManager::inputManager.setWindow(GameManager::window.windowInstance);

    glm::vec2 mousePosition = GameManager::inputManager.getMousePosition();

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

    //Reset rotation
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_KP_9) == GLFW_PRESS) {
        parent.rotation.x = 0;
        parent.rotation.y = 0;
        parent.rotation.z = 0;
    }

    //Camera Movement
    if(glfwGetKey(GameManager::window.windowInstance,GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) moveSpeed *= 2;

    parent.position.x += moveSpeed * deltaTime * GameManager::inputManager.getInputDirection("left","right");
    parent.position.z += moveSpeed * deltaTime * GameManager::inputManager.getInputDirection("forward","backward");
    parent.position.y += moveSpeed * deltaTime * GameManager::inputManager.getInputDirection("up","down");

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
