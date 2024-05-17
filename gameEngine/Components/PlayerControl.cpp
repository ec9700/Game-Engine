//
// Created by subto on 5/17/2024.
//
#include "PlayerControl.h"
glm::vec3 velcoity;
void PlayerControl::initial(Entity &parent) {

}

void PlayerControl::update(Entity &parent, double &deltaTime) {

    parent.move(velcoity.operator*=(deltaTime));
}

void PlayerControl::reset(Entity &parent) {

}
