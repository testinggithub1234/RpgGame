#ifndef RPGGAME_NPC_H
#define RPGGAME_NPC_H


#include <SFML/Graphics.hpp>

class Npc : public sf::Drawable {
public:
    Npc();

    void Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    sf::RectangleShape sprite;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Texture texture;
};


#endif //RPGGAME_NPC_H
