#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Level.h"

class Player : public sf::Drawable {
public:
    Player() { }

    void Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void Execute(sf::Keyboard::Key key, Level level);

    void Update();

    sf::RectangleShape sprite;

    sf::Vector2f getPosition();

    sf::Vector2f getPixelPosition();

    sf::Vector2f getSize();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Texture texture;

    sf::FloatRect boundingBox;

    sf::Clock clock;
};


#endif //RPGGAME_PLAYER_H
