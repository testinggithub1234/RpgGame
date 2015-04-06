#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
public:
    Player() { }

    void Init(sf::Vector2f pos);

    sf::RectangleShape sprite;

    void Update();

    void Execute(sf::Keyboard::Key key);

    sf::Vector2f getPosition();

    sf::Vector2f getSize();

private:

    sf::FloatRect boundingBox;
    sf::Clock clock;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //RPGGAME_PLAYER_H
