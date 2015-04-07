#ifndef RPGGAME_COLLISION_H
#define RPGGAME_COLLISION_H

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Level.h"

bool isPlayerCollidingWithNpcs() {
    return false;
}

bool isPlayerCollidingWithObjects(sf::Vector2f playerPos, Level level) {
    if (playerPos.x < 0 or playerPos.y < 0 or playerPos.x >= level.width or playerPos.y >= level.height) {
        return true;
    }

    if (isPlayerCollidingWithNpcs()) {
        return true;
    }

    return level.solidObjects[playerPos.x + playerPos.y * level.width] == true;

}


#endif //RPGGAME_COLLISION_H
