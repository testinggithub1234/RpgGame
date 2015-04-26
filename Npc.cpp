#include "Npc.h"

Npc::Npc(sf::Vector2f pos, sf::Vector2f size, sf::Texture &texture) {
    actor = new Actor();
    actor->init(pos, size, texture);
    actor->addAnimationDown(7, 0);
    actor->addAnimationDown(6, 0);
    actor->addAnimationDown(7, 0);
    actor->addAnimationDown(8, 0);
    actor->addAnimationLeft(7, 1);
    actor->addAnimationLeft(6, 1);
    actor->addAnimationLeft(7, 1);
    actor->addAnimationLeft(8, 1);
    actor->addAnimationRight(7, 2);
    actor->addAnimationRight(6, 2);
    actor->addAnimationRight(7, 2);
    actor->addAnimationRight(8, 2);
    actor->addAnimationUp(7, 3);
    actor->addAnimationUp(6, 3);
    actor->addAnimationUp(7, 3);
    actor->addAnimationUp(8, 3);
}

void Npc::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    actor->draw(target);
}

void Npc::update(sf::Time frameTime) {
    actor->update(frameTime);
}

sf::FloatRect Npc::getGlobalBounds() {
    sf::FloatRect rect;
    return actor->getGlobalBounds();
}

void Npc::movement() {
    actor->movement();
}

