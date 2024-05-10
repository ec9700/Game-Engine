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
            std::string type = typeid(*component).name();
            component->reset(*this);
            //pool.put( component);
            delete component;
        }
        componentVector.clear();
        pool.put(this);
}

/*void Entity::dontCrash() {
    pool.dontCrash();
}*/

