//
// Created by subto on 3/18/2024.
//

#include "GameManager.h"
#include "Component.h"

void GameManager::initial(float (&vertices)[], int sizeOfVertices) {
    renderManager.initialize(vertices,sizeOfVertices);
}

void GameManager::update(const Entity &camera, float windowWidth, float windowHeight, GLFWwindow *window) {

    double deltaTime = glfwGetTime() - lastTime;
    lastTime = glfwGetTime();

    for(Entity &entity : entityVector) {
        for(Component *component : entity.componentVector) {
            component->update(entity,deltaTime);
        }
        renderManager.render(entity,*shaderCollection,windowWidth,windowHeight,window,camera);
    }

}
