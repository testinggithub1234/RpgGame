#ifndef RPGGAME_COLLISION_H
#define RPGGAME_COLLISION_H

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Level.h"

bool isPlayerCollidingWithObjects(sf::Vector2f playerPos, Level level) {
    if(playerPos.x < 0 or playerPos.y < 0  or playerPos.x / 32 >= level.width or playerPos.y / 32 >= level.height){
        return true;
    }

    if(level.solidObjects[playerPos.x / 32 + playerPos.y / 32 * level.width] == true){
        return true;
    }
}


#endif //RPGGAME_COLLISION_H
