//
// Created by subto on 2/6/2024.
//

#ifndef GAMELIB_TEXTURE_H
#define GAMELIB_TEXTURE_H


#include <STB/stb_image.h>

#include <iostream>
#include <glad/glad.h>

class Texture {

public:
    unsigned int textureData;
    Texture(const char *fileName) {
        glGenTextures(1, &textureData);
        glBindTexture(GL_TEXTURE_2D, textureData);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(fileName,&width,&height,&nrChannels,0);
        if(data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "Failed to load texture "<< fileName << "\n";
        }
        stbi_image_free(data);

    }


};


#endif //GAMELIB_TEXTURE_H
