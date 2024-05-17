#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "STB/stb_image.h"
#include "gameEngine/Texture.h"
#include "gameEngine/Entity.h"
#include "gameEngine/RenderManager.h"
#include "gameEngine/InputManager.h"
#include "gameEngine/GameManager.h"
#include "gameEngine/Components/Spin.h"
#include "gameEngine/Components/RenderComponent.h"
#include "gameEngine/Components/CameraControl.h"
#include <vector>

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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main() {

    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Window", NULL, NULL);

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
    std::vector<float> vertices = {
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

    Texture texture( relativePath.append("/Textures/thing.jpg").c_str() );


    //RenderManager renderManager = RenderManager();
    GameManager::initial(window);
    GameManager::shaderCollection = &shaderCollection;




    //renderManager.initialize(vertices,sizeof(vertices)); //<<<< HERE!!!!!!

    double lastTime = 0;
    Entity* camera = Entity::newEntity();
    RenderManager::camera = camera;
    camera->addComponent<CameraControl>();

    //Entities
    int max = 100;

    for(int i=0; i<max; i++) {
        Entity* entity = Entity::newEntity();
        entity->texture = texture; //fixme Move texture to renderComponent
        entity->position.y = -max/2 + i;
        entity->size = glm::vec3(1,1,1);
        entity->addComponent<Spin>();

        RenderComponent* renderComponent = entity->addComponent<RenderComponent>();
        renderComponent->setShaderCollection(shaderCollection);
        renderComponent->setVertices(vertices);
    }

    auto* input = new InputManager(window);
    //unsigned long frameCount;
    while(!glfwWindowShouldClose(GameManager::window.windowInstance)) {
        _sleep(1); //Ignore that this is deprecated, temporary fix for limiting frames

        if (glfwGetKey(GameManager::window.windowInstance, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(GameManager::window.windowInstance, true);
        }

        GameManager::update();

        glfwSwapBuffers(GameManager::window.windowInstance);
        glfwPollEvents();
    }

    glfwTerminate();
    GameManager::dispose();


return 0;
}
