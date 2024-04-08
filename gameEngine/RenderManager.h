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

class RenderManager {
private:
    //unsigned static int EBO;
    unsigned int VAO;
    unsigned int VBO;



public:
    void initialize(float (&vertices)[], int sizeOfVertices);

    void render(const Entity& entity, ShaderCollection shaderCollection, float windowWidth, float windowHeight, GLFWwindow* window, const Entity& camera) const;

    void dispose();


};


#endif //GAMELIB_RENDERMANAGER_H
