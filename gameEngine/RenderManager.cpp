//
// Created by subto on 3/14/2024.
//

#include "RenderManager.h"
#include "GameManager.h"

static unsigned int VAO;
static unsigned int VBO;
Entity* RenderManager::camera;

void RenderManager::initialize() {

    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glEnable(GL_DEPTH_TEST);
}

void RenderManager::render(const Entity &entity, ShaderCollection shaderCollection, std::vector<float> vertices,unsigned long sizeOfVertices) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, entity.texture.textureData);

    int x = glfwGetTime()/2;
    //Magic number: +900
    //Explanation ^^^: If this number isn't added onto the vertices' size, it won't display all vertices. FIGURE OUT WHY!!!! 200 per triangle
    glBufferData(GL_ARRAY_BUFFER, vertices.size()+900, vertices.data(), GL_STATIC_DRAW);

    shaderCollection.use();

    glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view          = glm::mat4(1.0f);
    glm::mat4 projection    = glm::mat4(1.0f);

    model = glm::translate(model, entity.position);
    model = glm::rotate(model, glm::radians(entity.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(entity.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(entity.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, entity.scale);


    /*view = glm::lookAt(camera.position,
                       glm::vec3(0.0f, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f));*/
    view = glm::rotate(view, glm::radians(camera->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, glm::radians(camera->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::rotate(view, glm::radians(camera->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    view = glm::translate(view, camera->position);
    view = glm::scale(view, camera->scale);

    projection = glm::perspective(glm::radians(45.0f), (float)GameManager::window.windowWidth / (float)GameManager::window.windowHeight, 0.1f, 100.0f);

    //Spin
    //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.01f));



    unsigned int modelLocation = glGetUniformLocation(shaderCollection.shaderProgramID, "model");
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

    unsigned int viewLocation = glGetUniformLocation(shaderCollection.shaderProgramID, "view");
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));

    unsigned int projectionLocation = glGetUniformLocation(shaderCollection.shaderProgramID, "projection");
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES,0,36);

}

void RenderManager::dispose() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(1, &EBO);
}