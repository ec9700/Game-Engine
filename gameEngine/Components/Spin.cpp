//
// Created by subto on 4/3/2024.
//

#include "Spin.h"

void Spin::initial(Entity& parent) {
//fixme Call this

}
void Spin::update(Entity &parent, double& deltaTime) {
    parent.rotation += 5*deltaTime*parent.position.y;
}

void Spin::reset(Entity& parent) {

}

