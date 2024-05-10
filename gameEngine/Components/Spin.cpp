//
// Created by subto on 4/3/2024.
//

#include "Spin.h"
#include "RenderComponent.h"


static std::vector<float> vertices = {
        -0.5f, -0.5f, -0.5f, 1,0,0, 0, 0,
        0.5f, -0.5f, -0.5f, 0,1,0, 1, 0,
        0.5f,  0.5f, -0.5f, 0,0,1, 1,1,
        0.5f,  0.5f, -0.5f, 0,0,1, 1,1,
        -0.5f,  0.5f, -0.5f, 1, 1, 0, 0, 1,
        -0.5f, -0.5f, -0.5f, 1,0,0, 0, 0,

        -0.5f, -0.5f, 0.5f, 1,0,0, 0, 0,
        0.5f, -0.5f, 0.5f, 0,1,0, 1, 0,
        0.5f,  0.5f, 0.5f, 0,0,1, 1,1,
        0.5f,  0.5f, 0.5f, 0,0,1, 1,1,
        -0.5f,  0.5f, 0.5f, 1, 1, 0, 0, 1,
        -0.5f, -0.5f, 0.5f, 1,0,0, 0, 0,

        -0.5f, 0.5f, 0.5f, 1,0,0, 1, 0,
        -0.5f, 0.5f, -0.5f, 0,1,0, 1, 1,
        -0.5f,  -0.5f, -0.5f, 0,0,1, 0,1,
        -0.5f,  -0.5f, -0.5f, 0,0,1, 0,1,
        -0.5f,  -0.5f, 0.5f, 1, 1, 0, 0, 0,
        -0.5f, 0.5f, 0.5f, 1,0,0, 1, 0,

        0.5f, 0.5f, 0.5f, 1,0,0, 1, 0,
        0.5f, 0.5f, -0.5f, 0,1,0, 1, 1,
        0.5f,  -0.5f, -0.5f, 0,0,1, 0,1,
        0.5f,  -0.5f, -0.5f, 0,0,1, 0,1,
        0.5f,  -0.5f, 0.5f, 1, 1, 0, 0, 0,
        0.5f, 0.5f, 0.5f, 1,0,0, 1, 0,
        //Possible next 2
        -0.5f, -0.5f, -0.5f, 1,0,0, 0, 1,
        0.5f, -0.5f, -0.5f, 0,1,0, 1, 1,
        0.5f,  -0.5f, 0.5f, 0,0,1, 1,0,
        0.5f,  -0.5f, 0.5f, 0,0,1, 1, 0,
        -0.5f,  -0.5f, 0.5f, 1, 1, 0, 0, 0,
        -0.5f, -0.5f, -0.5f, 1, 0, 0, 0,1,

        -0.5f, 0.5f, -0.5f, 1,0,0, 0, 1,
        0.5f, 0.5f, -0.5f, 0,1,0, 1, 1,
        0.5f,  0.5f, 0.5f, 0,0,1, 1,0,
        0.5f,  0.5f, 0.5f, 0,0,1, 1, 0,
        -0.5f,  0.5f, 0.5f, 1, 1, 0, 0, 0,
        -0.5f, 0.5f, -0.5f, 1, 0, 0, 0,1,
};

void Spin::initial(Entity& parent) {

}
void Spin::update(Entity &parent, double& deltaTime) {
    parent.rotation += 5*deltaTime*parent.position.y;
    //entity->destroy();

    //Entity::dontCrash();

    //Entity::dontCrash();

    //if( (glfwGetTime()*5)-50>parent.position.y) parent.destroy();
    //if( (glfwGetTime()*5)-50>parent.position.y) parent.destroy();
    //parent.position.y += sin(glfwGetTime()*(parent.position.y/10))*8;
}

void Spin::reset(Entity& parent) {

}

