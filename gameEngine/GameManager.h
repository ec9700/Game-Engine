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
#include "InputManager.cpp"
class Entity;


class GameManager {

private:
    //static double lastTime;
    GameManager() = default;
    static std::vector<Entity*> entityVector;
public:
    static InputManager inputManager;
    static ShaderCollection *shaderCollection;
    static Window window;
    static Entity* currentEntityUpdated;

    /**
     * Runs initialize for @ref ::window and @ref RenderManager
     * @param window
     */
    static void initial(GLFWwindow* window);

    /**
     * Runs every frame calling @ref Component::update() on each @ref Component found in @ref ::entityVector
     */
    static void update();

    /**
     * Runs dispose for @ref RenderManager and deletes all @ref Entity found in @ref ::entityVector
     */
    static void dispose();

    friend Entity;

};


#endif //GAMELIB_GAMEMANAGER_H
