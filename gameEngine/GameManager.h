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
#include "Window.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class GameManager {

private:
    //static double lastTime;
    GameManager() = default;
public:
    static ShaderCollection *shaderCollection;
    static Window window;
    static void initial(GLFWwindow* window);

    static void update(const Entity& camera);


    static std::vector<Entity> entityVector;

};


#endif //GAMELIB_GAMEMANAGER_H
