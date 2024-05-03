//
// Created by subto on 4/8/2024.
//

#include "CameraControl.h"
#include "../GameManager.h"
#include "../inputManager.h"
#include "../inputManager.cpp"
#include "../vector2.h"
inputManager input=*new inputManager(GameManager::window.windowInstance);
vector2 mousePositionLast=*new vector2(0,0);
void CameraControl::initial(Entity& parent) {

}

void CameraControl::update(Entity &parent, double& deltaTime) {
//Camera Look (KP = numpad)
    auto mousePosition=input.getMousePosition();
    parent.rotation.x+=(mousePosition.x-mousePositionLast.x);
    int rotateSpeed = 90;
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_LEFT) == GLFW_PRESS) {
        parent.rotation.y -= rotateSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        parent.rotation.y += rotateSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_UP) == GLFW_PRESS) {
        parent.rotation.x -= rotateSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_DOWN) == GLFW_PRESS) {
        parent.rotation.x += rotateSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_KP_1) == GLFW_PRESS) {
        parent.rotation.z -= rotateSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_KP_2) == GLFW_PRESS) {
        parent.rotation.z += rotateSpeed * deltaTime;
    }
    //Reset rotation
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_KP_9) == GLFW_PRESS) {
        parent.rotation.x = 0;
        parent.rotation.y = 0;
        parent.rotation.z = 0;
    }

    //Camera Movement
    int moveSpeed = 5;
    if(glfwGetKey(GameManager::window.windowInstance,GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) moveSpeed *= 2;

    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_D) == GLFW_PRESS) {
        parent.position.x -= moveSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_A) == GLFW_PRESS) {
        parent.position.x += moveSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_W) == GLFW_PRESS) {
        parent.position.z += moveSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_S) == GLFW_PRESS) {
        parent.position.z -= moveSpeed * deltaTime;
    }
    if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_SPACE) == GLFW_PRESS) {
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
    mousePositionLast.x=mousePosition.x;
    mousePositionLast.y=mousePosition.y;
}

void CameraControl::reset(Entity& parent) {

}
