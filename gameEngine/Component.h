//
// Created by subto on 3/18/2024.
//

#ifndef GAMELIB_COMPONENT_H
#define GAMELIB_COMPONENT_H


class Component {
public:

    //Change "{}" to "= 0;"
    virtual void initial() {}
    virtual void update() {}
    virtual void dispose() {}

    Component() {

    }

};


#endif //GAMELIB_COMPONENT_H
