#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "STB/stb_image.h"
#include "Texture.h"
#include "gameEngine/Entity.h"
#include "gameEngine/RenderManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <direct.h>
#include <filesystem>

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
    /*unsigned int indices[] = {
            0, 1, 3, 1, 2, 3,
            4, 5, 7,5, 6, 7,
            8, 9, 11,9, 10, 11,
            12, 13, 15,13, 14, 15,
    };*/

    /*unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    //Wire Frame
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //Initialization of non OpenGL stuff

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glEnable(GL_DEPTH_TEST);*/

    //Wire Frame
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //std::cout << argv[0];

    std::string fileName = __FILE_NAME__;

    std::string relativePath = __FILE__;
    relativePath.erase(relativePath.size()-fileName.length(),fileName.length());


    Texture texture( relativePath.append("/Textures/thing.jpg").c_str() );

    RenderManager renderManager = RenderManager();

    renderManager.initialize(vertices,sizeof(vertices)); //<<<< HERE!!!!!!

    double lastTime = 0;
    //glm::vec3 viewVec = glm::vec3(0,0,-3);
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

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        float moveSpeedMultiplier = camera.position.z / -3;
        int moveSpeed = 5;

        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            camera.rotation.y -= 90 * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            camera.rotation.y += 90 * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            camera.rotation.x -= 90 * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            camera.rotation.x += 90 * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_KP_1) == GLFW_PRESS) {
            camera.rotation.z -= 90 * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS) {
            camera.rotation.z += 90 * deltaTime;
        }

        //glm::vec3 facedDirection = glm::normalize(camera.rotation);

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
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            camera.position.y -= moveSpeed * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            camera.position.y += moveSpeed * deltaTime;
        }

        glClearColor(.2f, .2, .8, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT);

        //entityVector[0].position.x += 2*deltaTime;

        //camera.rotation.x -= 30*deltaTime;
        //camera.rotation.y += 360*deltaTime;
        //camera.rotation.z += 360*deltaTime;

        for (Entity &entity : entityVector) {
            //entity.position.x += 2 * deltaTime;
            //entity.scale.x += -2*deltaTime;
            //entity.scale.z += -2*deltaTime;

            entity.rotation += 5*deltaTime*entity.position.y;

            //entity.scale += 1*deltaTime;

            //entity.position.x += 1*deltaTime;

            renderManager.render(entity, shaderCollection, windowWidth, windowHeight, window, camera);

        }

        glfwSwapBuffers(window);
        glfwPollEvents();


    }

    renderManager.dispose();

glfwTerminate();

return 0;
}
