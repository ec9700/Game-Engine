//
// Created by subto on 5/17/2024.
//

#ifndef GAMELIB_PLAYERCONTROL_H
#define GAMELIB_PLAYERCONTROL_H


#include "../Component.h"

class PlayerControl : Component {
    void initial(Entity& parent) override;
    void update(Entity &parent, double& deltaTime) override;
    void reset(Entity& parent) override;

    friend Entity;
};


#endif //GAMELIB_PLAYERCONTROL_H
