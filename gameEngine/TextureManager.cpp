//
// Created by pr2200 on 5/16/2024.
//
#include "TextureManager.h"

Texture TextureManager::findByName(std::string name) {
    return textureMap.at(name);
}

void TextureManager::addToMap(std::string name, Texture texture) {

}

