#include "Collision.h"
#include <iostream>

using namespace std;

Collision::Collision() {

}

bool Collision::isPlayerColliding(sf::Vector2f playerPos, sf::Vector2f levelDimensions,
                                  std::vector<bool> solidObjects) {
    if (playerPos.x < 0 or playerPos.y < 0 or playerPos.x > levelDimensions.x - 1 or
        playerPos.y > levelDimensions.y - 1) {
        return true;
    }

    return false;
}
