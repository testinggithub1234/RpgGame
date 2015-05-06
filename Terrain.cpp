#include <iostream>
#include "Terrain.h"

Terrain::Terrain() {

}

void Terrain::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform = getTransform();
    states.texture = &texture->getTexture(texLocation);
    target.draw(&vertices[0], vertices.size(), sf::Quads, states);
}

void Terrain::setView(sf::View view) {
    sf::FloatRect initRect(sf::Vector2f(view.getCenter().x - (view.getSize().x) / 2,
                                        view.getCenter().y - (view.getSize().y) / 2),
                           view.getSize());
    float x, y;

    x = initRect.left;
    y = initRect.top;

    if (x < 0) {
        x = 0;
    }

    if (y < 0) {
        y = 0;
    }

    if (x > 32 * 30 - 800) {
        x = 32 * 30 - 800;
    }
    if (y > 32 * 30 - 600) {
        y = 32 * 30 - 600;
    }

    vertices.clear();
    vertices.push_back(
            sf::Vertex(sf::Vector2f(x, y), sf::Vector2f(x, y)));
    vertices.push_back(
            sf::Vertex(sf::Vector2f(800 + x, y), sf::Vector2f(800 + x, y)));
    vertices.push_back(
            sf::Vertex(sf::Vector2f(800 + x, 600 + y), sf::Vector2f(800 + x, 600 + y)));
    vertices.push_back(
            sf::Vertex(sf::Vector2f(x, 600 + y), sf::Vector2f(x, 600 + y)));
}

Terrain::Terrain(std::string texLoc) {
    texture = new TextureManager();
    texLocation = texLoc;
    texture->getTexture(texLoc);
}
