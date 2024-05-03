//
// Created by subto on 1/25/2024.
//

#include "Shader.h"

Shader::Shader(char *shaderSource, GLenum shaderType) {
    this->shaderType = shaderType;
    shaderID = glCreateShader(shaderType);

    glShaderSource(shaderID, 1, &shaderSource, NULL);
    glCompileShader(shaderID);

    int success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "FAILED TO COMPILE SHADER "<<shaderType<<" "<<shaderID<<"\n"<<infoLog;
    }

}
