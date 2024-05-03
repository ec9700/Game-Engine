//
// Created by subto on 4/3/2024.
//

#include "Spin.h"

void Spin::initial(Entity& parent) {

}

void Spin::update(Entity &parent, double& deltaTime) {
    parent.rotation += 5*deltaTime*parent.position.y;

    //Entity* entity = Entity::newEntity();
    //entity->destroy();

    Entity::dontCrash();

    //if( (glfwGetTime()*5)-50>parent.position.y) parent.destroy();
    //if( (glfwGetTime()*5)-50>parent.position.y) parent.destroy();
    //parent.position.y += sin(glfwGetTime()*(parent.position.y/10))*8;
}

void Spin::reset(Entity& parent) {

}
