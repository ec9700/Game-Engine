#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "STB/stb_image.h"
#include "gameEngine/Texture.h"
#include "gameEngine/Entity.h"
#include "gameEngine/RenderManager.h"
#include "gameEngine/inputManager.h"
#include "gameEngine/inputManager.cpp"
#include <vector>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

const char* vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "layout (location = 1) in vec3 aColor;\n"
                                 "layout (location = 2) in vec2 aTextureCoord;\n"
                                 //"uniform mat4 transform;\n"
                                 "uniform mat4 view;\n"
                                 "uniform mat4 projection;\n"
                                 "uniform mat4 model;\n"
                                 "out vec3 color;\n"
                                 "out vec2 textureCoord;\n"
                                 "\n"
                                 "void main()\n"
                                 "{\n"
                                 "gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
                                 "color = aColor;\n"
                                 "textureCoord = aTextureCoord;\n"
                                 "}";
const char* fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "in vec2 textureCoord;\n"
                                   "in vec3 color;\n"
                                   "uniform sampler2D texture;\n"
                                   //"uniform vec4 color;\n"
                                   "\n"
                                   "void main()\n"
                                   "{\n"
                                   "FragColor = texture(texture,textureCoord) * vec4(color, 1.0);\n"
                                   "}";


int main() {
    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Window", NULL, NULL);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    std::cout << "Hola Y'all\n";

    Shader vertexShader((char *) vertexShaderSource, GL_VERTEX_SHADER);
    Shader fragmentShader((char *) fragmentShaderSource, GL_FRAGMENT_SHADER);

    ShaderCollection shaderCollection(vertexShader,fragmentShader);

    // x,y,z, r,g,b, texture corner x, texture corner y
    float vertices[] = {
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

    std::string fileName = __FILE_NAME__;

    std::string relativePath = __FILE__;
    relativePath.erase(relativePath.size()-fileName.length(),fileName.length());


    Texture texture("C:/Users/ck6100/Documents/Game-Engine/Textures/thing.jpg");

    RenderManager renderManager = RenderManager();

    renderManager.initialize(vertices,sizeof(vertices)); //<<<< HERE!!!!!!

    double lastTime = 0;
    Entity camera = Entity();

    //Entities
    std::vector<Entity> entityVector;
    int max = 100;

    for(int i=0; i<max; i++) {
        Entity entity;
        entity.texture = texture;
        entity.position.y = -max/2 + i;
        entity.scale = glm::vec3(1,1,1);
        entityVector.push_back(entity);
    }


    while(!glfwWindowShouldClose(window)) {

        double deltaTime = glfwGetTime() - lastTime;
        lastTime = glfwGetTime();

        auto* input = new inputManager(window);

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }


        //Camera Look (KP = numpad)
        int rotateSpeed = 90;
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            camera.rotation.y -= rotateSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            camera.rotation.y += rotateSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            camera.rotation.x -= rotateSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            camera.rotation.x += rotateSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_KP_1) == GLFW_PRESS) {
            camera.rotation.z -= rotateSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS) {
            camera.rotation.z += rotateSpeed * deltaTime;
        }
        //Reset rotation
        if (glfwGetKey(window, GLFW_KEY_KP_9) == GLFW_PRESS) {
            camera.rotation.x = 0;
            camera.rotation.y = 0;
            camera.rotation.z = 0;
        }

        //Camera Movement
        int moveSpeed = 5;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            camera.position.x -= moveSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            camera.position.x += moveSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            camera.position.z += moveSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            camera.position.z -= moveSpeed * deltaTime;
        }
        if (input->getInputPressed(input->keyCodeSpace)) {
            camera.position.y -= moveSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            camera.position.y += moveSpeed * deltaTime;
        }
        //Reset position
        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
            camera.position.x = 0;
            camera.position.y = 0;
            camera.position.z = 0;
        }

        glClearColor(.2f, .2, .8, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT);


        for (Entity &entity : entityVector) {

            entity.rotation += 5*deltaTime*entity.position.y;

            //entity.scale += 1*deltaTime;

            //entity.position.x += 1*deltaTime;

            renderManager.render(entity, shaderCollection, windowWidth, windowHeight, window, camera);

        }



        glfwSwapBuffers(window);
        glfwPollEvents();

        _sleep(1);
    }

    renderManager.dispose();

glfwTerminate();

return 0;
}
