#ifndef RPGGAME_TEXTURES_H
#define RPGGAME_TEXTURES_H


#include <SFML/Graphics/Texture.hpp>
#include <map>

class TextureManager {
public:
    TextureManager();
    sf::Texture& getTexture(const std::string& texLocation);
    void deleteTexture(sf::Texture &texture);
    void deleteTexture(std::string texLocation);

private:
    std::map<std::string, sf::Texture> textures;


};


#endif //RPGGAME_TEXTURES_H

