#ifndef RPGGAME_TILEMAP_H
#define RPGGAME_TILEMAP_H

#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include <vector>
#include <string>

class TileMap : public sf::Drawable {
public:
    TileMap() { }

    void Load(const std::string &tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width,
              unsigned int height, sf::View cameraView);

    void setView(sf::View cameraView);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    int width, height;

    sf::FloatRect screenRect;

    TextureManager texture;
    sf::View cameraView;
    std::vector<sf::Sprite> sprites;
};


#endif //RPGGAME_TILEMAP_H
