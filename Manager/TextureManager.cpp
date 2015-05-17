#include <iostream>
#include "TextureManager.h"

TextureManager::TextureManager() {

}

sf::Texture &TextureManager::getTexture(const std::string &texLocation) {
    for (auto it = textures.begin(); it != textures.end(); ++it){
        if(texLocation == it->first){
            return it->second;
        }
    }

    sf::Texture texture;

    if(texture.loadFromFile(texLocation)) {
        textures[texLocation] = texture;
        std::cout << "DEBUG_MESSAGE: loading image: "<< texLocation << "\n";
        return  textures[texLocation];
    }

    std::cout << "GAME_ERROR: Image: \""<< texLocation <<"\" was not found. It is filled with an empty image.\n";
    textures[texLocation] = texture;

    return textures[texLocation];
}

void TextureManager::deleteTexture(sf::Texture &texture) {
    for(auto it = textures.begin(); it != textures.end(); ++it){
        if(&texture == &it->second){
            textures.erase(it);
        }
    }
}

void TextureManager::deleteTexture(std::string texLocation) {
    auto it = textures.find(texLocation);
    if(it != textures.end()){
        textures.erase(it);
    }
}
