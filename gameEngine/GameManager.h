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
    double lastTime;
public:
    ShaderCollection *shaderCollection;
    std::vector<Entity> entityVector;

    void initial(float (&vertices)[], int sizeOfVertices);

    void update(const Entity& camera, float windowWidth, float windowHeight, GLFWwindow* window);


};


#endif //GAMELIB_GAMEMANAGER_H
