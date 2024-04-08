//
// Created by subto on 1/25/2024.
//

#include "ShaderCollection.h"

ShaderCollection::ShaderCollection(Shader vertexShader, Shader fragmentShader) {
    this->vertexShader = &vertexShader;
    this->fragmentShader = &fragmentShader;

    shaderProgramID = glCreateProgram();

    glAttachShader(shaderProgramID, vertexShader.shaderID);
    glAttachShader(shaderProgramID, fragmentShader.shaderID);
    glLinkProgram(shaderProgramID);

    int success;
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetShaderInfoLog(shaderProgramID, 512, NULL, infoLog);
        std::cout << "LINKING FAILED FOR SHADER COLLECTION "<<shaderProgramID<<"\n"<<infoLog;
    }
}

void ShaderCollection::use() {
    glUseProgram(shaderProgramID);
}

void ShaderCollection::setUniform(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), (int)value);
}

void ShaderCollection::setUniform(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), value);
}

void ShaderCollection::setUniform(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(shaderProgramID, name.c_str()), value);
}
