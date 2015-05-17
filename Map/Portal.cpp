#include "Portal.h"

Portal::Portal() {

}

void Portal::init(sf::Vector2f portalPos, sf::Vector2f size, std::string target, sf::Vector2f playerPos) {
    portal.left = playerPos.x;
    portal.top = playerPos.y;
    portal.width = size.x;
    portal.height = size.y;
    level = target;
    this->playerPos = playerPos;
}

sf::FloatRect Portal::getGlobalBounds() {
    return  portal;
}

sf::Vector2f Portal::getPlayerPosition() {
    return playerPos;
}

std::string Portal::getLevel() {
    return level;
}
