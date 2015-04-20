#include "Collision.h"
#include <iostream>

using namespace std;

Collision::Collision() {

}

bool Collision::isPlayerColliding(sf::Vector2f playerPos, sf::Vector2f destination, sf::Vector2f levelDimensions,
                                  std::vector<bool> solidObjects) {

    if (destination.x < 0 or destination.y < 0 or destination.x > levelDimensions.x - 1 or
        destination.y > levelDimensions.y - 1) {
        return true;
    }

    if (solidObjects[destination.x + destination.y * levelDimensions.x]) {
        return true;
    }

    return false;
}
