#ifndef RPGGAME_NPC_H
#define RPGGAME_NPC_H

#include <SFML/Graphics.hpp>
#include "../../Actor/Actor.h"

class Npc : public sf::Drawable {
public:
    Npc(sf::Vector2f pos, sf::Vector2f size, sf::Texture &texture);

    void movement();

    sf::Vector2f getPosition();

    void update(sf::Time frameTime);

    sf::FloatRect getGlobalBounds();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    Actor *actor;
};


#endif //RPGGAME_NPC_H
