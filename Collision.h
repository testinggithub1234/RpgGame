#ifndef RPGGAME_COLLISION_H
#define RPGGAME_COLLISION_H

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Level.h"
#include "Npc.h"

bool isPlayerCollidingWithNpcs(std::vector<Npc> npcList, sf::FloatRect playerBoundingBox) {
    for(auto it = npcList.begin(); it != npcList.end();++it){
        if(playerBoundingBox.intersects(it->boundingBox)){
            return true;
        }
    }
    return false;
}

bool isPlayerCollidingWithObjects(sf::Vector2f playerPos, std::vector<bool> solidObjects, std::vector<Npc> npcList, sf::FloatRect playerBoundingBox) {
    if (playerPos.x < 0 or playerPos.y < 0 or playerPos.x >= 16 or playerPos.y >= 8) {
        return true;
    }

    if(isPlayerCollidingWithNpcs(npcList, playerBoundingBox)){
        return true;
    }

    return solidObjects[playerPos.x + playerPos.y * 16] == true;
}


#endif //RPGGAME_COLLISION_H
