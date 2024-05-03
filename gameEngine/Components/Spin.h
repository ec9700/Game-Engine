//
// Created by subto on 4/3/2024.
//

#ifndef GAMELIB_SPIN_H
#define GAMELIB_SPIN_H


#include "../Component.h"

class Spin : public Component {
    void initial(Entity& parent) override;
    void update(Entity &parent, double& deltaTime) override;
    void reset(Entity& parent) override;

    void blankMethod();
};


#endif //GAMELIB_SPIN_H
