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
#include "HitboxData.h"

class Component;
class GameManager;
class HitboxData;

class Entity {



private:
    static ComplexPool pool;
    std::vector<Component*> componentVector;
    Entity() = default;
    std::vector<HitboxData*> hitboxAreaChecks;


public:
    glm::vec3 position = glm::vec3(0,0,0);
    glm::vec3 size = glm::vec3(1,1,1);
    glm::vec3 rotation = glm::vec3(0,0,0);
    Texture texture = nullptr;

    /**
     * Tests if any @ref HitboxComponent of name @p layerName overlaps with a box defined by @p position and @p size, calling @p onHit if true
     * @param layerName @ref std::string Name of hitbox to check for
     * @param position @ref glm::vec3 Position of defined box
     * @param size @ref glm::vec3 Size of defined box
     * @param onHit @code void (*onHit)(Entity*)@endcode Function to call on overlap
     */
    void testArea(std::string layerName, glm::vec3 position, glm::vec3 size, void (*onHit)(Entity*) );
    /**
     * Tests if any @ref HitboxComponent of name @p layerName overlaps with a box defined by @p x,@p y,@p z, and @p width,@p height,@p depth, calling @p onHit if true
     * @param layerName @ref std::string Name of hitbox to check for
     * @param x @ref float X position of defined box
     * @param y @ref float Y position of defined box
     * @param z @ref float Z position of defined box
     * @param width @ref float width of defined box
     * @param height @ref float width of defined box
     * @param depth @ref float width of defined box
     * @param onHit @code void (*onHit)(Entity*)@endcode Function to call on overlap
     */
    void testArea(std::string layerName, float x, float y, float z, float width, float height, float depth, void (*onHit)(Entity*) );
    /**
     * Tests if any @ref HitboxComponent of name @p layerName overlaps with a box defined by the @code position@endcode and @code size@endcode properties @ref Entity calling @p onHit if true
     * @param layerName @ref std::string Name of hitbox to check for
     * @param onHit @code void (*onHit)(Entity*)@endcode Function to call on overlap
     */
    void testArea(std::string layerName, void (*onHit)(Entity*) );

    /**
     * Rotates this @ref Entity by @p x,@p y, and @p z
     * @param x @ref float X rotation
     * @param y @ref float Y rotation
     * @param z @ref float Z rotation
     */
    void rotate(float x, float y, float z);
    /**
     * Moves this @ref Entity by @p x,@p y, and @p z
     * @param x @ref float X to move
     * @param y @ref float Y to move
     * @param z @ref float Z to move
     */
    void move(float x, float y, float z);
    /**
     * Scales this @ref Entity by @p x,@p y, and @p z
     * @param x @ref float X to scale
     * @param y @ref float Y to scale
     * @param z @ref float Z to scale
     */
    void scale(float x, float y, float z);

    /**
     * Rotates this @ref Entity by @p xyz
     * @param xyz @ref glm::vec3 Vector to rotate by
     */
    void rotate(glm::vec3 xyz);
    /**
     * Moves this @ref Entity by @p xyz
     * @param xyz @ref glm::vec3 Vector to move by
     */
    void move(glm::vec3 xyz);
    /**
     * Scales this @ref Entity by @p xyz
     * @param xyz @ref glm::vec3 Vector to scale by
     */
    void scale(glm::vec3 xyz);

    /**
     * Sets @ref Entity::rotation to @p x,@p y,@p z
     * @param x @ref float X of rotation
     * @param y @ref float Y of rotation
     * @param z @ref float Z of rotation
     */
    void setRotation(float x, float y, float z);
    /**
     * Sets @ref Entity::position to @p x,@p y,@p z
     * @param x @ref float X of position
     * @param y @ref float Y of position
     * @param z @ref float Z of position
     */
    void setPosition(float x, float y, float z);
    /**
     * Sets @ref Entity::size to @p x,@p y,@p z
     * @param x @ref float X of size
     * @param y @ref float Y of size
     * @param z @ref float Z of size
     */
    void setSize(float x, float y, float z);
    /**
     * Sets @ref Entity::rotation to @p xyz
     * @param xyz @ref glm::vec3 to set rotation to
     */
    void setRotation(glm::vec3 xyz);
    /**
     * Sets @ref Entity::position to @p xyz
     * @param xyz @ref glm::vec3 to set position to
     */
    void setPosition(glm::vec3 xyz);
    /**
     * Sets @ref Entity::size to @p xyz
     * @param xyz @ref glm::vec3 to set size to
     */
    void setSize(glm::vec3 xyz);

    /**
     * Calls @ref Component::reset and deletes (when working it will pool components) all child @ref Component and puts this entity back in the list
     */
    void destroy();

    /**
     * Adds a @ref Component of type @p T to an @ref Entity, calling @ref Component::initial on the component
     * @tparam T Type of component
     * @return New @ref Component of type @p T
     */
    template<typename T> //fixme Only allow components to be created (In Java: T extends Component)
    T* addComponent() {
        T* component = pool.get<T>();
        componentVector.push_back(component);
        component->initial(*this);
        return component;
    }

    /**
     * @return A pointer to a new @ref Entity
     */
    static Entity* newEntity();

    friend GameManager;
    friend ObjectPool<Entity>;

};


#endif //GAMELIB_ENTITY_H
