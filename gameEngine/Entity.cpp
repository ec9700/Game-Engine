//
// Created by subto on 3/15/2024.
//

#include "Entity.h"
#include "Component.h"
#include "VectorMethods.h"
#include "Components/RenderComponent.h"
#include "HitboxData.h"
#include "Components/HitboxComponent.h"

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

void Entity::testArea(std::string layerName, void (*onHit)(Entity *)) {
    testArea(layerName, onHit, this->position, this->size);
}

void Entity::rotate(glm::vec3 xyz) {
    rotate(xyz.x,xyz.y,xyz.z);
}

void Entity::move(glm::vec3 xyz) {
    move(xyz.x,xyz.y,xyz.z);
}

void Entity::scale(glm::vec3 xyz) {
    scale(xyz.x,xyz.y,xyz.z);
}

void Entity::setRotation(glm::vec3 xyz) {
    setRotation(xyz.x,xyz.y,xyz.z);
}

void Entity::setPosition(glm::vec3 xyz) {
    setPosition(xyz.x,xyz.y,xyz.z);
}
void Entity::setSize(glm::vec3 xyz) {
    setSize(xyz.x,xyz.y,xyz.z);
}

void Entity::testArea(std::string layerName, void (*onHit)(Entity *), glm::vec3 position, glm::vec3 size) {
    HitboxData* hitboxData = new HitboxData;
    hitboxData->position = position;
    hitboxData->size = size;
    hitboxData->layerName = layerName;
    hitboxData->onHit = onHit;

    hitboxAreaChecks.push_back(hitboxData);
    HitboxComponent::hitboxAreaCheckMap[layerName].push_back(hitboxData);
}

void
Entity::testArea(std::string layerName, void (*onHit)(Entity *), float x, float y, float z, float width, float height, float depth) {
    testArea(layerName,onHit, glm::vec3(x,y,z), glm::vec3(width,height,depth));
}

void Entity::testAdjacentArea(std::string layerName, void (*onHit)(Entity *), glm::vec3 position, glm::vec3 size) {
    testArea(layerName, onHit, position+this->position, size);
}

void Entity::testAdjacentArea(std::string layerName, void (*onHit)(Entity *), float x, float y, float z, float width, float height, float depth) {
    testAdjacentArea(layerName, onHit, glm::vec3(x, y, z), glm::vec3(width, height, depth));
}



/*void Entity::dontCrash() {
    pool.dontCrash();
}*/

