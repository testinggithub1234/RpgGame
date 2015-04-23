#include <iostream>
#include "EntityManager.h"

EntityManager::EntityManager() {

}

void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < npcList.size(); i++) {
        target.draw(npcList[i], states);
    }
}

void EntityManager::update(sf::Time frameTime) {
    for (auto it = npcList.begin(); it != npcList.end(); ++it) {
        it->update(frameTime);
    }

    updateBounds();
}

void EntityManager::addNpc(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    Npc npc(sf::Vector2f(pos.x * size.x, pos.y * size.x + size.x - size.y), size, texture.getTexture(texLocation));;
    npcList.push_back(npc);
}

std::vector<sf::FloatRect> EntityManager::getNpcsGlobalBounds() {
    return npcsBounds;
}

void EntityManager::updateBounds() {
    npcsBounds.clear();
    for (auto it = npcList.begin(); it != npcList.end(); ++it) {
        npcsBounds.push_back(it->getGlobalBounds());
    }
}

void EntityManager::npcMovement() {
    for (auto it = npcList.begin(); it != npcList.end(); ++it) {
        it->movement();
    }
}
