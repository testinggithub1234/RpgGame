#ifndef RPGGAME_NPC_H
#define RPGGAME_NPC_H


#include <SFML/Graphics.hpp>
#include "Actor.h"

class Npc : public sf::Drawable {
public:
    Npc();

    void Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void Movement();

    void Update();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    Actor actor;
};


#endif //RPGGAME_NPC_H
