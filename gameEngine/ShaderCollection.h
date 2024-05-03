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
    ShaderCollection(Shader vertexShader, Shader fragmentShader);

    void use();

    void setUniform(const std::string &name, bool value) const;
    void setUniform(const std::string &name, int value) const;
    void setUniform(const std::string &name, float value) const;

private:
    Shader *vertexShader, *fragmentShader;
};


#endif //GAMELIB_SHADERCOLLECTION_H
