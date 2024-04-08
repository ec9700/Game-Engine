//
// Created by subto on 3/18/2024.
//

#ifndef GAMELIB_COMPONENT_H
#define GAMELIB_COMPONENT_H


#include "Entity.h"

class Component {
public:
    //Change "{}" to "= 0;"
    virtual void initial(Entity parent) = 0;
    virtual void update(Entity &parent, double deltaTime) = 0;
    virtual void dispose(Entity parent) = 0;

    Component() = default;

};


#endif //GAMELIB_COMPONENT_H
