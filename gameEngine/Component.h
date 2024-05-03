//
// Created by subto on 3/18/2024.
//

#ifndef GAMELIB_COMPONENT_H
#define GAMELIB_COMPONENT_H


#include "Entity.h"
#include "GameManager.h"

class Component {
protected:
    virtual void initial(Entity& parent) = 0;
    virtual void update(Entity &parent, double& deltaTime) = 0;
    virtual void reset(Entity& parent) = 0;

    virtual ~Component() = default;

    Component() = default;

    friend Entity;
    friend GameManager;

};


#endif //GAMELIB_COMPONENT_H
