//
// Created by subto on 3/18/2024.
//

#include "GameManager.h"
#include "Component.h"

std::vector<Entity> GameManager::entityVector;
ShaderCollection* GameManager::shaderCollection;
Window GameManager::window;
static double lastTime;

void GameManager::initial(GLFWwindow *window) {

    GameManager::window.initial();
    GameManager::window.windowInstance = window;

    RenderManager::initialize();
}

void GameManager::update(const Entity &camera) {

    double deltaTime = glfwGetTime() - lastTime;
    lastTime = glfwGetTime();
    for(Entity &entity : entityVector) {
        for(Component *component : entity.componentVector) {
            component->update(entity,deltaTime);
        }
        //RenderManager::render(entity,*shaderCollection,vertices,sizeOfVertices);
    }

}
