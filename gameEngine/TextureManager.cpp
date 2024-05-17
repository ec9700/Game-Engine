//
// Created by pr2200 on 5/16/2024.
//
#include "TextureManager.h"
std::unordered_map<std::string,Texture*> TextureManager::textureMap;

/**
 * @param name key to the desired texture
 * @return the texture pointer
 */
Texture* TextureManager::findByName(std::string name) {
    return textureMap.at(name);
}

/**
 *
 * @param name the name/key of the texture/value to be added to the map
 * @param texture_file_name the file
 */
void TextureManager::addTexture(std::string name, std::string texture_file_name) {
    std::string relative_path = __FILE__;
    // 29 = "gameEngine\TextureManager.cpp"
    // easy way out
    relative_path = relative_path.erase(relative_path.size() - 29, 29);
    relative_path.append("Textures\\");
    // relative_path = "...\Game-Engine\Textures\"
    Texture *texture = new Texture(relative_path.append(texture_file_name).c_str());
    textureMap.insert(std::make_pair(name, texture));
}
void TextureManager::addTexture(std::string texture_file_name) {
    std::string relative_path = __FILE__;
    relative_path = relative_path.erase(relative_path.size() - 29, 29);
    relative_path.append("Textures\\");
    Texture *texture = new Texture(relative_path.append(texture_file_name).c_str());
    size_t dotpos = texture_file_name.find_last_of('.');
    texture_file_name = texture_file_name.substr(0,dotpos);
    textureMap.insert(std::make_pair(texture_file_name, texture));
}
