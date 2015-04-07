#include "EntityManager.h"

EntityManager::EntityManager() {

}

void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < npcs.size(); i++){
        target.draw(npcs[i], states);
    }
}

void EntityManager::Init() {

}

