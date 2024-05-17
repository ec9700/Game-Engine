//
// Created by pr2200 on 5/16/2024.
//

#ifndef GAMELIB_TEXTUREMANAGER_H
#define GAMELIB_TEXTUREMANAGER_H

#include <unordered_map>
#include <string>
#include "Texture.h"

class TextureManager {
public:
    static std::unordered_map<std::string,Texture*> textureMap;
    static Texture* findByName(std::string name);
    static void addTexture(std::string name,std::string texture_file_name);
    static void addTexture(std::string texture_file_name);
};


#endif //GAMELIB_TEXTUREMANAGER_H


//unordered_map<std::string,Texture*>
