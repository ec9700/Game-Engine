//
// Created by subto on 3/14/2024.
//

#ifndef GAMELIB_RENDERMANAGER_H
#define GAMELIB_RENDERMANAGER_H


#include <glad/glad.h>
#include <glm/fwd.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Texture.h"
#include "ShaderCollection.h"
#include "GLFW/glfw3.h"
#include "Entity.h"
class Entity;
class RenderManager {
private:
    //unsigned static int EBO;

    RenderManager() = default;



public:
    static Entity* camera;

    static void initialize();

    //Original Parameter: float (&vertices)[] instead of float* vertices
    static void render(const Entity &entity, ShaderCollection shaderCollection, std::vector<float> vertices);

    static void dispose();


};


#endif //GAMELIB_RENDERMANAGER_H
