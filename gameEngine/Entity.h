//
// Created by subto on 3/15/2024.
//

#ifndef GAMELIB_ENTITY_H
#define GAMELIB_ENTITY_H


#include <glm/vec3.hpp>
#include <vector>
#include "Texture.h"
class Component;

class Entity {
public:
    glm::vec3 position = glm::vec3(0,0,0);
    glm::vec3 scale = glm::vec3(1,1,1);
    glm::vec3 rotation = glm::vec3(0,0,0);
    Texture texture = nullptr;
    std::vector<Component*> componentVector;

    Entity() = default;

};


#endif //GAMELIB_ENTITY_H
