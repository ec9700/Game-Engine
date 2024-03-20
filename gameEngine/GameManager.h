//
// Created by subto on 3/18/2024.
//

#ifndef GAMELIB_GAMEMANAGER_H
#define GAMELIB_GAMEMANAGER_H


#include "Entity.h"
#include "RenderManager.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "STB/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class GameManager {

private:
    RenderManager renderManager;
public:
    ShaderCollection shaderCollection;
    std::vector<Entity> entityList;

    void initial() {

    }

    void update(Entity camera) {
        for(Entity &entity : entityList) {
            for(Component &component : entity.componentList) {
                component.update();
            }
            //renderManager.render(entity,shaderCollection,);
        }
    }


};


#endif //GAMELIB_GAMEMANAGER_H
