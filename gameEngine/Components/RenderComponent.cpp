//
// Created by subto on 4/8/2024.
//

#include "RenderComponent.h"
#include "../RenderManager.h"



void RenderComponent::initial(Entity parent) {

}

void RenderComponent::update(Entity &parent, double deltaTime) {
    RenderManager::render(parent,*shaderCollection,*vertices,vertices->size());
}

void RenderComponent::dispose(Entity parent) {

}

void RenderComponent::setShaderCollection(ShaderCollection &shaderCollection) {
    this->shaderCollection = &shaderCollection;
}

void RenderComponent::setVertices(std::vector<float> &vertices) {
    this->vertices = &vertices;
}
