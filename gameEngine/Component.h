//
// Created by subto on 3/18/2024.
//

#ifndef GAMELIB_COMPONENT_H
#define GAMELIB_COMPONENT_H


class Component {
public:
    virtual void initial() = 0;
    virtual void update() = 0;
    virtual void dispose() = 0;
};


#endif //GAMELIB_COMPONENT_H
