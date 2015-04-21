#include "EntityManager.h"

EntityManager::EntityManager() {

}

void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < npcList.size(); i++) {
        target.draw(npcList[i], states);
    }
}

void EntityManager::Init() {
    npcList.clear();
}

void EntityManager::Update() {
    for(auto it = npcList.begin(); it != npcList.end(); ++it){
        it->Update();
    }
}

void EntityManager::addNpc(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    Npc npc;
//    npc.Init(sf::Vector2f(pos.x * 32, pos.y * 32), size, texture.getTexture(texLocation));
    npcList.push_back(npc);
}


