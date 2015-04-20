#include "TileMap.h"

void TileMap::Load(const std::string &tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width,
                   unsigned int height, sf::View view) {
    this->cameraView = cameraView;
    this->height = height;
    this->width = width;

    sf::FloatRect initRect(sf::Vector2f(cameraView.getCenter().x - (cameraView.getSize().x)/2, cameraView.getCenter().y - (cameraView.getSize().y)/2) , cameraView.getSize());

    screenRect = initRect;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int tileNumber = tiles[i + j * width];
            int tx = tileNumber % (texture.getTexture(tileset).getSize().x / tileSize.x);
            int ty = tileNumber / (texture.getTexture(tileset).getSize().x / tileSize.x);

            sf::IntRect subRect;
            subRect.left = tx * tileSize.x;
            subRect.top = ty * tileSize.y;
            subRect.width = tileSize.x;
            subRect.height = tileSize.y;

            sf::Sprite sprite(texture.getTexture(tileset), subRect);
            sprite.setPosition(i * tileSize.x, j * tileSize.y);

            sprites.push_back(sprite);
        }
    }
}

void TileMap::setView(sf::View cameraView) {
    this->cameraView = cameraView;
    sf::FloatRect initRect(sf::Vector2f(cameraView.getCenter().x - (cameraView.getSize().x)/2, cameraView.getCenter().y - (cameraView.getSize().y)/2) , cameraView.getSize());

    screenRect = initRect;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (screenRect.intersects(sprites[i + j * width].getGlobalBounds())) {
                target.draw(sprites[i + j * width]);
            }
        }
    }
}


