//
// Created by subto on 5/17/2024.
//
#include "PlayerControl.h"
glm::vec3 velcoity;

void onTouchGround(Entity* entity) {
    velcoity.y = 1;
    entity->position.y = 100;
}

void PlayerControl::initial(Entity &parent) {

}

void PlayerControl::update(Entity &parent, double &deltaTime) {
    velcoity.y += 500*deltaTime;
    parent.testAdjacentArea("ground", &onTouchGround, 0, -1, 0,2,2,2);
    parent.move(velcoity.operator*=(deltaTime));
}

void PlayerControl::reset(Entity &parent) {

}
