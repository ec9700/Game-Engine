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

    Shader(char *shaderSource, GLenum shaderType);

private:
    GLenum shaderType;
};


#endif //GAMELIB_SHADER_H
