//
// Created by subto on 3/15/2024.
//

#include "Entity.h"
#include "Component.h"
#include "VectorMethods.h"

ComplexPool Entity::pool;

Entity* Entity::newEntity() {
    Entity* entity = pool.get<Entity>();
    GameManager::entityVector.push_back(entity);
    return entity;
}

void Entity::destroy() {
        VectorMethods::removeObject(GameManager::entityVector, this); //Remove object from GameManager to stop update
        for(Component* component : componentVector) {
            component->reset(*this);
            delete component; //Bug here? Check to make sure this is correct
        }
        componentVector.clear();
        pool.put(this);
}

/*void Entity::dontCrash() {
    pool.dontCrash();
}*/

