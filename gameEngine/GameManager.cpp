//
// Created by subto on 3/18/2024.
//

#include "GameManager.h"
#include "Component.h"

std::vector<Entity*> GameManager::entityVector;
ShaderCollection* GameManager::shaderCollection;
Window GameManager::window;
static double lastTime;

void GameManager::initial(GLFWwindow *window) {

    GameManager::window.initial();
    GameManager::window.windowInstance = window;

    RenderManager::initialize();
}

void GameManager::update() {

    double deltaTime = glfwGetTime() - lastTime;
    lastTime = glfwGetTime();
    //Start render
    glClearColor(.2f, .2, .8, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    for(Entity *entity : entityVector) {
        for(Component *component : entity->componentVector) {
            component->update(*entity,deltaTime);
        }

    }

}

void GameManager::dispose() {
    //Exit code: -107374940 (0xC0000374) Make just use new for camera
    RenderManager::dispose();
    for(Entity *entity : entityVector) {
        //delete &entity;
    }
    entityVector.clear();
}
