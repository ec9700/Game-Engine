//
// Created by subto on 2/6/2024.
//

#ifndef GAMELIB_TEXTURE_H
#define GAMELIB_TEXTURE_H


#include "STB/stb_image.h"


#include <iostream>
#include "glad/glad.h"

class Texture {

public:
    unsigned int textureData{};
    Texture(const char *fileName);


};


#endif //GAMELIB_TEXTURE_H
