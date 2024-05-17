//
// Created by subto on 3/18/2024.
//

#ifndef GAMELIB_COMPONENT_H
#define GAMELIB_COMPONENT_H


#include "Entity.h"
#include "GameManager.h"

class Component {
protected:
    /**
     * Called when created by @ref Entity::addComponent<T>()
     * @param parent @ref Entity Parent this @ref Component is attached too
     */
    virtual void initial(Entity& parent) = 0;
    /**
     * Called every frame by @ref GameManager::update()
     * @param parent @ref Entity Parent this @ref Component is attached too
     * @param deltaTime @ref double Time passed from the last frame
     */
    virtual void update(Entity &parent, double& deltaTime) = 0;
    /**
     * Called when destroyed by @ref Entity::destroy()
     * @param parent @ref Entity Parent this @ref Component is attached too
     */
    virtual void reset(Entity& parent) = 0;

    virtual ~Component() = default;

    Component() = default;

    friend Entity;
    friend GameManager;

};


#endif //GAMELIB_COMPONENT_H
