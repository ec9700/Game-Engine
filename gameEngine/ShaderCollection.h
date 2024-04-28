//
// Created by subto on 1/25/2024.
//

#ifndef GAMELIB_SHADERCOLLECTION_H
#define GAMELIB_SHADERCOLLECTION_H


#include "Shader.h"
class Texture;

class ShaderCollection {
public:
    unsigned int shaderProgramID;
    ShaderCollection(Shader vertexShader, Shader fragmentShader) {
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

    void use() {
        glUseProgram(shaderProgramID);
    }

    void setUniform(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), (int)value);
    }
    void setUniform(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), value);
    }
    void setUniform(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(shaderProgramID, name.c_str()), value);
    }

private:
    Shader *vertexShader, *fragmentShader;
};


#endif //GAMELIB_SHADERCOLLECTION_H
