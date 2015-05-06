#include <iostream>
#include "EntityManager.h"
#include <algorithm>

EntityManager::EntityManager() {
    player.init(sf::Vector2f(0, 16), sf::Vector2f(32, 48), "Resources/player.png");
}

void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < npcList.size(); i++) {
        if (i == playerDrawOrder) {
            target.draw(player);
        }
        target.draw(npcList[i]);
    }
    if (playerDrawOrder == -1) {
        target.draw(player);
    }
}

void EntityManager::update(sf::Time frameTime) {
    for (auto it = npcList.begin(); it != npcList.end(); ++it) {
        it->update(frameTime);
    }

    player.update(frameTime);
    updateDrawOrder();

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

void EntityManager::playerExecute() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.execute();

    }
    else {
        player.stop();
    }
    if (collision.isPlayerColliding(player.getDestination(), player.getGlobalBounds(),
                                    getNpcsGlobalBounds())) {
        player.undoMovement();
    }
    player.movement();
}

void EntityManager::loadData(Collision collision, sf::Vector2f size) {
    this->collision = collision;
    this->levelSize = size;
}

bool sortCondition(Npc &s1, Npc &s2) {
    return s1.getPosition().y < s2.getPosition().y;
}

void EntityManager::updateDrawOrder() {
    std::sort(npcList.begin(), npcList.end(), sortCondition);
    updatePlayerOrder();
}

void EntityManager::updatePlayerOrder() {
    for (int i = 0; i < npcList.size(); i++) {
        if (npcList[i].getPosition().y > player.getPosition().y) {
            playerDrawOrder = i;
            return;
        }
        else {
            playerDrawOrder = -1;
        }
    }
}
