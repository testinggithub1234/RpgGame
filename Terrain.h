#ifndef RPGGAME_TERRAIN_H
#define RPGGAME_TERRAIN_H

#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include <vector>
#include <string>

class Terrain : public sf::Drawable {
public:
    Terrain() { }

    bool Load(const std::string &tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width,
              unsigned int height, sf::View cameraView);

    void setView(sf::View cameraView);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::FloatRect screenRect;
    std::vector<sf::Vertex> m_vertices;
    sf::Texture m_tileset;
};


#endif //RPGGAME_TILEMAP_H
