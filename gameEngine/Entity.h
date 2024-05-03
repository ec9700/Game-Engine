//
// Created by subto on 3/15/2024.
//

#ifndef GAMELIB_ENTITY_H
#define GAMELIB_ENTITY_H


#include <glm/vec3.hpp>
#include <vector>
#include <unordered_map>
#include "Texture.h"
#include "ObjectPool.h"
#include "GameManager.h"
#include "ComplexPool.h"

class Component;
class GameManager;

class Entity {
private:
    static ComplexPool pool;
    std::vector<Component*> componentVector;
    Entity() = default;
public:
    glm::vec3 position = glm::vec3(0,0,0);
    glm::vec3 scale = glm::vec3(1,1,1);
    glm::vec3 rotation = glm::vec3(0,0,0);
    Texture texture = nullptr;

    void destroy();

    static void dontCrash();

    template<typename T>
    T* addComponent() {
        T* component = pool.get<T>();
        componentVector.push_back(component);
        return component;
    }

    static Entity* newEntity();

    friend GameManager;
    friend ObjectPool<Entity>;

};


#endif //GAMELIB_ENTITY_H
