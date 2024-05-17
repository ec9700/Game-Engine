//
// Created by subto on 3/15/2024.
//

#include "Entity.h"
#include "Component.h"
#include "VectorMethods.h"
#include "Components/RenderComponent.h"

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
            std::string type2 = typeid(typeof(*component)).name();
            std::string type3 = typeid(decltype(*component)).name();
            //std::string type4 = typeid().name();
            component->reset(*this);
            //pool.put( component);
            //<std::remove_pointer<std::remove_reference<decltype(*component)>::type>::type>

            //pool.put(component); //fixme make this work !!!IMPORTANT!!!!
            delete component;
        }
        componentVector.clear();
        pool.put(this);
}

void Entity::rotate(float x, float y, float z) {
    this->rotation.x += x;
    this->rotation.y += y;
    this->rotation.z += z;
}

void Entity::move(float x, float y, float z) {
    this->position.x += x;
    this->position.y += y;
    this->position.z += z;
}

void Entity::scale(float x, float y, float z) {
    this->size += x;
    this->size += y;
    this->size += z;
}

void Entity::setRotation(float x, float y, float z) {
    this->rotation.x = x;
    this->rotation.y = y;
    this->rotation.z = z;
}

void Entity::setPosition(float x, float y, float z) {
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;
}

void Entity::setSize(float x, float y, float z) {
    this->size.x = x;
    this->size.y = y;
    this->size.z = z;
}

/*void Entity::dontCrash() {
    pool.dontCrash();
}*/

