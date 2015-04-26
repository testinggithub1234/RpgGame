#include <iostream>
#include "TileMap.h"

bool TileMap::Load(const std::string &tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width,
                   unsigned int height, sf::View view) {
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset)) {
        std::cout << "GAME_ERROR: Image: " << tileset << " was not found. It is filled with an empty image.\n";
        return false;
    }
    else {
        std::cout << "DEBUG_MESSAGE: loading image: " << tileset << "\n";
    }

    // resize the vertex array to fit the level size
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j) {
            // get the current tile number
            int tileNumber = tiles[i + j * width];
            if(tileNumber != -1) {
                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex *quad = &m_vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }
        }

    return true;

}

void TileMap::setView(sf::View view) {
    sf::FloatRect initRect(sf::Vector2f(view.getCenter().x - (view.getSize().x) / 2,
                                        view.getCenter().y - (view.getSize().y) / 2),
                           view.getSize());
    screenRect = initRect;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform = getTransform();

    states.texture = &m_tileset;

    target.draw(&m_vertices[0], m_vertices.size(), sf::PrimitiveType::Quads, states);

    /*
    sf::FloatRect rect;
    for (int i = 0; i < m_vertices.size(); i += 4) {

        rect.width = 32;
        rect.height = 32;
        rect.top = m_vertices[i].position.y;
        rect.left = m_vertices[i].position.x;
        if (rect.intersects(screenRect)) {
            target.draw(&m_vertices[i], 4, sf::PrimitiveType::Quads, states);
        }
    }*/
}


