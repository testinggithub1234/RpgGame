#include "Npc.h"

Npc::Npc() {

}

void Npc::Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    texture.loadFromFile(texLocation);
    sprite.setSize(size);
    sprite.setPosition(pos);
    sprite.setTexture(&texture);
}

void Npc::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

