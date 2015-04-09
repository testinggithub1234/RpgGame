#ifndef RPGGAME_NPC_H
#define RPGGAME_NPC_H


#include <SFML/Graphics.hpp>

class Npc : public sf::Drawable {
public:
    Npc();

    sf::FloatRect boundingBox;

    void Init(sf::Vector2f pos, sf::Vector2f size, sf::Texture &texture);

    void Update();

private:
    sf::RectangleShape sprite;


    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //RPGGAME_NPC_H
