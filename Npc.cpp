#include "Npc.h"

Npc::Npc() {

}

void Npc::Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    actor.init(pos, size, texLocation);
}

void Npc::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(actor);
}

void Npc::Update() {
}

void Npc::Movement() {
    actor.movement();
}
