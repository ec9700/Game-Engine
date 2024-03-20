//
// Created by subto on 1/25/2024.
//

#ifndef GAMELIB_SHADER_H
#define GAMELIB_SHADER_H


#include <glad/glad.h>
#include <iostream>

class Shader {
public:
    unsigned int shaderID;

    Shader(char *shaderSource, GLenum shaderType) {
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

private:
    GLenum shaderType;
};


#endif //GAMELIB_SHADER_H
